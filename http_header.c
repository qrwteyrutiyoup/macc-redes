#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "http_header.h"


/*================================= DEFINES ==================================*/



/*================================ FUNCTIONS =================================*/


/**
 * Adds a new Header to the HTTP Headers
 * @param header The first header of the list.
 * @param fName The header's field name.
 * @param fValue The header's field value.
 * @return The list's first header.
 * 
 * Code example:
 * HTTPHeader *hd;
 *
 * hd = addField(hd, "content-type", "text-html");
 *
 */ 
HTTPHeader *addHeader(HTTPHeader *header, char *fName, char *fValue)
{
	HTTPHeader *auxHeader = NULL, *prevHeader = NULL;
	int namelen, valuelen;

	// Insert at the end of the list
	auxHeader = header;
	while(auxHeader) {
		prevHeader = auxHeader;
		auxHeader = auxHeader->next;
	}

	auxHeader = malloc(sizeof(HTTPHeader));

	namelen = strlen(fName);
	auxHeader->fName = malloc(namelen + 1);
	strcpy(auxHeader->fName, fName);

	valuelen = strlen(fValue);
	auxHeader->fValue = malloc(valuelen + 1);
	strcpy(auxHeader->fValue, fValue);

	auxHeader->next = NULL;
	auxHeader->prev = prevHeader;
	if (prevHeader) prevHeader->next = auxHeader;

	// If a new list head was created, return it (auxHeader).
	return (prevHeader == NULL) ? auxHeader : header;
}


/**
 * Removes a header from HTTP Headers
 * @param header The first header of the list.
 * @param fName The header's field name.
 * @return The list's first header.
 */
HTTPHeader *removeHeader(HTTPHeader *header, char *fName)
{
	HTTPHeader *auxHeader = NULL;

	auxHeader = header;
	while (auxHeader && strcmp(auxHeader->fName, fName) != 0)
		auxHeader = auxHeader->next;

	if (auxHeader != NULL) {
		if (auxHeader->prev == NULL) { // Removing the head
			header = auxHeader->next;
			header->prev = NULL;
		} else { // Removing in the list
			if (auxHeader->next)
				auxHeader->next->prev = auxHeader->prev;
			if (auxHeader->prev)
				auxHeader->prev->next = auxHeader->next;
		}
		free(auxHeader->fName);
		free(auxHeader->fValue);
		free(auxHeader);
	}

	return header;
}


/**
 * Searches a header by the headers's field name.
 * @return The field value 
 * @return NULL, if the field name doesn't exist
 */
char *getHeaderValueByFieldName(HTTPHeader *header, char *name)
{
	while (header && strcmp(header->fName, name) != 0) {
		header = header->next;
	}
	
	return (header)? header->fValue : NULL;
}


/**
 * Removes the headers and free the memory..
 */
void destroyHeader(HTTPHeader *header)
{
	HTTPHeader *auxHeader = NULL;

	while(header) {
		auxHeader = header;
		header = header->next;
		free(auxHeader->fName);
		free(auxHeader->fValue);
		free(auxHeader);
		auxHeader = NULL;
	}
}


/**
 * Serializes a HTTP header for transmission.
 * @param hd The header
 * @param [out] buffer The buffer that storage the serialized header
 * @param sizeBuf The size of the buffer
 * @return the number of bytes serialized. If it returns a greater than sizeBuf, it means that a 
 * bigger buffer is needed.
 */
size_t serializeHeader(HTTPHeader *hd, char *buffer, size_t sizeBuf)
{
	size_t hdLen = 0; // The lenght of the serialized header
	size_t offset = 0;

	memset(buffer, 0, sizeBuf);
	while(hd && offset < sizeBuf) {
		hdLen = 0;
		hdLen += strlen(hd->fName);
		hdLen += strlen(hd->fValue);
		hdLen += 4; // The lenght of the following chars together: ':', ' ', 'CR' and 'LF'.
		if (offset + hdLen > sizeBuf) {
			offset += hdLen;
			break;
		} else {
			sprintf(buffer+offset, "%s: %s", hd->fName, hd->fValue);
			strcat(buffer, CRLF); 	// Header terminator
			offset += hdLen;
			hd = hd->next;
		}
	}
	
	return offset;
}


void printHeader(HTTPHeader *header)
{
	printf("** headers\n");
	while (header) {
		printf("Field: [%s] \t Value: [%s]\n", header->fName, header->fValue);
		header = header->next;
	}
	printf(" headers **\n");
}
