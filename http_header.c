#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "http_header.h"


/*================================= DEFINES ==================================*/



/*================================ FUNCTIONS =================================*/


/**
 * Adds a new field to the HTTP Header
 * @return The header head.
 * 
 * Code example:
 * HTTPHeader *hd;
 *
 * hd = addField(hd, "content-type", "text-html");
 *
 */ 
HTTPHeader *addField(HTTPHeader *header, char *fName, char *fValue)
{
	HTTPHeader *auxHeader = NULL, *prevHeader = NULL;

	// Insert at the end of the list
	auxHeader = header;
	while(auxHeader) {
		prevHeader = auxHeader;
		auxHeader = auxHeader->next;
	}

	auxHeader = malloc(sizeof(HTTPHeader));
	auxHeader->fName = malloc(strlen(fName));
	strcpy(auxHeader->fName, fName);
	auxHeader->fValue = malloc(strlen(fValue));
	strcpy(auxHeader->fValue, fValue);
	auxHeader->next = NULL;
	auxHeader->prev = prevHeader;
	if (prevHeader) prevHeader->next = auxHeader;

	// If a new list head was created, return it (auxHeader).
	return (prevHeader == NULL) ? auxHeader : header;
}


/**
 * Removes a field from HTTP Header
 * @return The header head.
 */
HTTPHeader *removeField(HTTPHeader *header, char *fName)
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
 * Search the header for a field by field's name.
 * @return The field value 
 * @return NULL, if the field doesn't exist
 */
char *getFieldValueByName(HTTPHeader *header, char *name)
{
	while (header && strcmp(header->fName, name) != 0) {
		header = header->next;
	}
	
	return (header)? header->fValue : NULL;
}


/**
 * Removes the header and free the memory..
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


void printHeader(HTTPHeader *header)
{
	while (header)
	{
		printf("Field: %s \t Value: %s\n", header->fName, header->fValue);
		header = header->next;
	}
}
