#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

#include <sys/types.h>

/*================================= DEFINES ==================================*/
// Characters
#define SP			' '
#define HT			'\t'
#define CR			'\r'
#define LF			'\n'
#define CRLF			"\r\n"

// HTTP Field Names
#define	HTTP_CONTENT_LENGHT	"Content-Lenght"
#define HTTP_CONTENT_TYPE	"Content-Type"
#define HTTP_SERVER		"Server"


/*================================ STRUCTURES ================================*/

/**
 * An HTTP Header is a doubly-linked-list of fields. Each field is a pair 
 * (fName, fValue).
 *
 */
typedef struct st_HTTPHeader{
	char *fName; 	///< Field Name
	char *fValue; 	///< Field Value
	struct st_HTTPHeader *next;
	struct st_HTTPHeader *prev;
} HTTPHeader;


/*================================ PROTOTYPES ================================*/
HTTPHeader *addHeader(HTTPHeader *header, char *fName, char *fValue);
HTTPHeader *removeHeader(HTTPHeader *header, char *fName);
char *getHeaderValueByFieldName(HTTPHeader *header, char *fName);
size_t serializeHeader(HTTPHeader *hd, char *buffer, size_t sizeBuf);
void destroyHeader(HTTPHeader *header);


#endif /*  HTTP_HEADER_H  */

