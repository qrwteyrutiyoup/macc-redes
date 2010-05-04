#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "http_header.h"
#include "http_response.h"
#include "mime-types.h"

/*================================= DEFINES ==================================*/
#define ERROR_FILE_NOT_FOUND	"error_pages/not_found.htm"


/*================================ PROTOTYPES ================================*/
char *getContentType(char *filePath);

/*================================ FUNCTIONS =================================*/
HTTPResponse *createResponse(char *filePath)
{
	int status;
	HTTPResponse *newResp = NULL;
	struct stat fStat; // Entity Body stat

	newResp = (HTTPResponse*) malloc(sizeof(HTTPResponse));
	assert(newResp != NULL);
	memset(newResp, 0, sizeof(HTTPResponse));

	newResp->version = (char*) malloc(strlen(HTTP_SERVER_VERSION));
	assert(newResp->version != NULL);
	strcpy(newResp->version, HTTP_SERVER_VERSION);

	newResp->fdEntityBody = open(filePath, O_RDONLY);
	if (newResp->fdEntityBody < 0) {
		// Status Code
		newResp->statusCode = (char*)malloc(strlen(ST_CODE_NOT_FOUND));
		assert(newResp->statusCode != NULL);
		strcpy(newResp->statusCode, ST_CODE_NOT_FOUND);

		// Reason Phrase
		newResp->reasonPhrase = (char*)malloc(strlen(ST_PHRASE_NOT_FOUND));
		assert(newResp->reasonPhrase != NULL);
		strcpy(newResp->reasonPhrase, ST_PHRASE_NOT_FOUND);

		// EntityBody
		newResp->fdEntityBody = open(ERROR_FILE_NOT_FOUND, O_RDONLY);
		assert(newResp->fdEntityBody > 0);
		
		// Server header
		newResp->header = addHeader(newResp->header, HTTP_SERVER, HTTP_SERVER_FIELD);

		// Content-Type header
		newResp->header = addHeader(newResp->header, HTTP_CONTENT_TYPE, getContentType(ERROR_FILE_NOT_FOUND));
	} else {
		// Status Code
		newResp->statusCode = (char*)malloc(strlen(ST_CODE_OK));
		assert(newResp->statusCode != NULL);
		strcpy(newResp->statusCode, ST_CODE_OK);

		// Reason Phrase
		newResp->reasonPhrase = (char*)malloc(strlen(ST_PHRASE_OK));
		assert(newResp->reasonPhrase != NULL);
		strcpy(newResp->reasonPhrase, ST_PHRASE_OK);

		// EntityBody
		newResp->fdEntityBody = open(filePath, O_RDWR);
		
		// Server header
		newResp->header = addHeader(newResp->header, HTTP_SERVER, HTTP_SERVER_FIELD);

		// Content-Type header
		newResp->header = addHeader(newResp->header, HTTP_CONTENT_TYPE, getContentType(filePath));
	}

	status = fstat(newResp->fdEntityBody, &fStat);
	assert(status == 0);

	// If regular file, add Content-Length header
	if (S_ISREG(fStat.st_mode)) {
		char strbuf[32];
		sprintf(strbuf, "%i", (int)fStat.st_size);
		newResp->header = addHeader(newResp->header, HTTP_CONTENT_LENGTH, strbuf);
	}
	
	return newResp;
}


char *getContentType(char *filePath)
{
	int len = strlen(filePath);
	char *ext = NULL;;
	ext = strrchr(filePath,'.');

	if (ext != NULL && (ext - filePath < len)) {
		int i;
		struct mime_type *mt = get_mime_types();
		for (i = 0; i < MIMETYPE_COUNT; i++) {
			if (strcmp(ext + 1, mt[i].extension) == 0) {
				printf("mime-type: %s\n", mt[i].mimetype);
				return mt[i].mimetype;
			}
		}
	}

	return "text/html";
}


void destroyResponse(HTTPResponse *resp)
{
	if (resp == NULL)
		return;

	if (resp->version)
		free(resp->version);
	if (resp->statusCode)
		free(resp->statusCode);
	if (resp->reasonPhrase)
		free(resp->reasonPhrase);
	
	if (resp->fdEntityBody > 0)
		close(resp->fdEntityBody);

	if (resp->header)
		destroyHeader(resp->header);

	free(resp);
}


size_t serializeResponse(HTTPResponse *resp, char *buffer, size_t sizeBuf)
{
	size_t hdLen = 0; // Header length
	size_t offset = 0;

	memset(buffer, 0, sizeBuf);

	hdLen = strlen(resp->version) + strlen(" "); 
	if (offset + hdLen > sizeBuf) {
		return offset + hdLen;
	} else {
		strcat(buffer, resp->version);
		strcat(buffer, " ");
		offset += hdLen;
	}

	hdLen = strlen(resp->statusCode) + strlen(" "); 
	if (offset + hdLen > sizeBuf) { 
		return offset + hdLen;
	} else {
		strcat(buffer, resp->statusCode);
		strcat(buffer, " ");
		offset += hdLen;
	}
	
	hdLen = strlen(resp->reasonPhrase) + strlen(CRLF);
	if (offset + hdLen > sizeBuf) { 
		return offset + hdLen;
	} else {
		strcat(buffer, resp->reasonPhrase);
		strcat(buffer, CRLF);
		offset += hdLen;
	}

	offset += serializeHeader(resp->header, buffer + offset, sizeBuf - offset);

	hdLen = strlen(CRLF);
	if (offset + hdLen > sizeBuf) {
		return offset + hdLen;
	} else {
		strcat(buffer, CRLF);
		offset += hdLen;
	}

	return offset;
}

