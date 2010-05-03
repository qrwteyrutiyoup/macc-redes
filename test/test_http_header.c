#include <stdio.h>
#include "../http_header.h"


int main()
{
	HTTPHeader *hd = NULL;

	hd = addField(hd, "fd1", "vl1");
	hd = addField(hd, "fd2", "vl2");
	hd = addField(hd, "fd3", "vl3");
	hd = addField(hd, "fd4", "vl4");
	hd = addField(hd, "fd5", "vl5");
	hd = addField(hd, "fd6", "vl6");
	hd = addField(hd, "fd7", "vl7");

	printHeader(hd);

	printf("Removing fd7\n");
	hd = removeField(hd, "fd7");
	printHeader(hd);
	
	printf("Removing fd1\n");
	hd = removeField(hd, "fd1");
	printHeader(hd);
	
	printf("Removing fd4\n");
	hd = removeField(hd, "fd4");
	printHeader(hd);

	printf("Search field[fd5]: %s\n", getFieldValueByName(hd, "fd5"));
	printf("Search field[fd2]: %s\n", getFieldValueByName(hd, "fd2"));
	printf("Search field[fd6]: %s\n", getFieldValueByName(hd, "fd6"));
	printf("Search field[fd1]: %s\n", getFieldValueByName(hd, "fd1"));
	printf("Search field[fd7]: %s\n", getFieldValueByName(hd, "fd7"));

	printf("Destroying\n");
	destroyHeader(hd);

	return 0;
}
