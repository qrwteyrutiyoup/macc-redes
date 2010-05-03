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
HTTPHeader *addField(HTTPHeader *header, char *fName, char *fValue);
HTTPHeader *removeField(HTTPHeader *header, char *fName);
char *getFieldValueByName(HTTPHeader *header, char *fName);
void destroyHeader(HTTPHeader *header);


#endif /*  HTTP_HEADER_H  */

