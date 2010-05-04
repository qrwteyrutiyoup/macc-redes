#ifndef HTTP_REPONSE_H
#define HTTP_REPONSE_H

#include "http_header.h"

/*================================= DEFINES ==================================*/
//HTTP Server Version
#define HTTP_SERVER_VERSION		"HTTP/1.0"
#define HTTP_SERVER_FIELD		"Sergio and Vinicius Server"

//Status Codes and Reason Phrases.
#define ST_CODE_OK			"200"
#define ST_PHRASE_OK			"OK"

#define ST_CODE_CREATED			"201"
#define ST_PHRASE_CREATED		"Created"

#define ST_CODE_ACCEPCTED 		"202"
#define ST_PHRASE_ACCECPTED		"Accepted"

#define ST_CODE_NO_CONTENT 		"204"
#define ST_PHRASE_NO_CONTENT		"No Content"

#define ST_CODE_MOVED_PERMANENTLY	"301"
#define ST_PHRASE_MOVED_PERMANENTLY 	"Moved Permanently"

#define ST_CODE_MOVED_TEMPORALILY 	"302"
#define ST_PHRASE_MOVED_TEMPORALILY	"Moved Temporarily"

#define ST_CODE_NOT_MODIFIED		"304"
#define ST_PHRASE_NOT_MODIFIED		"Not Modified"

#define ST_CODE_BAD_REQUEST 		"400"
#define ST_PHRASE_BAD_REQUEST 		"Bad Request"

#define ST_CODE_UNAUTHORIZED		"401"
#define ST_PHRASE_UNAUTHORIZED 		"Unauthorized"

#define ST_CODE_FORBIDDEN		"403"
#define ST_PHRASE_FORBIDDEN	 	"Forbidden"

#define ST_CODE_NOT_FOUND 		"404"
#define ST_PHRASE_NOT_FOUND		"Not Found"

#define ST_CODE_INTERNAL_SERVER_ERROR	"500"
#define ST_PHRASE_INTERNAL_SERVER_ERROR	"Internal Server Error"

#define ST_CODE_ NOT_IMPLEMENTED 	"501"
#define ST_PHRASE_NOT_IMPLEMENTED	"Not Implemented"

#define ST_CODE_BAD_GATEWAY		"502"
#define ST_PHRASE_BAD_GATEWAY		"Bad Gateway"

#define ST_CODE_SERVICE_UNAVAILABLE	"503"
#define ST_PHRASE_SERVICE_UNAVAILABLE	"Service Unavailable"


/*================================ STRUCTURES ================================*/
/**
 *The HTTP Response
 */
typedef struct {
	char *version; 		///< The HTTP Version of the server
	char *statusCode; 	///< The transaction status code
	char *reasonPhrase;	///< A Description
	HTTPHeader *header;	///< The HTTP Headers
	int fdEntityBody;	///< A file descriptor to the Entity-body to be sent to the client
} HTTPResponse;


/*================================ PROTOTYPES ================================*/
//HTTPResponse *createResponse(HTTPRequest req);
HTTPResponse *createResponse(char *filePath);
void destroyResponse(HTTPResponse *resp);
size_t serializeResponse(HTTPResponse *resp, char *buffer, size_t sizeBuf);

#endif /*  HTTP_REPONSE_H  */

