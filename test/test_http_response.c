#include <stdio.h>
#include <string.h>
#include "../http_response.h"

int main()
{
	char buffer[512];
	int status;
	HTTPResponse *resp = NULL;

	resp = createResponse("../error_pages/not_found.htm");

	printf("Serializing Response\n");
	status = serializeResponse(resp, buffer, sizeof(buffer));
	printf("Buffer Size: %i Used Bytes: %i strlen(buffer):%i\n", sizeof(buffer), status, strlen(buffer));
	printf("%s", buffer);

	destroyResponse(resp);

	printf("End.\n");

	return 0;
}

