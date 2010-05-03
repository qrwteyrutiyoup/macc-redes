#include <stdio.h>
#include <string.h>
#include "../http_header.h"


int main()
{
	int status;
	char buffer[512];
	HTTPHeader *hd = NULL;

	hd = addHeader(hd, "fd1", "vl1");
	hd = addHeader(hd, "fd2", "vl2");
	hd = addHeader(hd, "fd3", "vl3");
	hd = addHeader(hd, "fd4", "vl4");
	hd = addHeader(hd, "fd5", "vl5");
	hd = addHeader(hd, "fd6", "vl6");
	hd = addHeader(hd, "fd7", "vl7");

	printHeader(hd);

	printf("Removing fd7\n");
	hd = removeHeader(hd, "fd7");
	printHeader(hd);
	
	printf("Removing fd1\n");
	hd = removeHeader(hd, "fd1");
	printHeader(hd);
	
	printf("Removing fd4\n");
	hd = removeHeader(hd, "fd4");
	printHeader(hd);

	printf("Search field[fd5]: %s\n", getHeaderValueByFieldName(hd, "fd5"));
	printf("Search field[fd2]: %s\n", getHeaderValueByFieldName(hd, "fd2"));
	printf("Search field[fd6]: %s\n", getHeaderValueByFieldName(hd, "fd6"));
	printf("Search field[fd1]: %s\n", getHeaderValueByFieldName(hd, "fd1"));
	printf("Search field[fd7]: %s\n", getHeaderValueByFieldName(hd, "fd7"));

	status = serializeHeader(hd, buffer, sizeof(buffer)); 
	printf("Serializing Header, bytes: %i. Contents below:\n%s", status, buffer); 
	printf("strlen(buffer): %i\n", strlen(buffer));

	printf("Destroying\n");
	destroyHeader(hd);
	printf("End.\n");

	return 0;
}
