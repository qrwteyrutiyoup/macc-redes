#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "http_response.h"

/*================================= DEFINES ==================================*/
#define LOG_FILE	"log/http_requests.log"
#define PORT		80
#define ROOT		"./web"

#define INDEXES_COUNT	2
#define INDEXES_MAXLEN	10
static char *indexes[INDEXES_COUNT] = {"index.html", "index.htm"};

/*================================ FUNCTIONS =================================*/

/**
 * Logs a message sent by the client.
 * Messages receibed by the server are appended in a file.
 *
 * @param file The file used to log messages.
 * @param message The message sent by the client to the server. 
 * @return The quantity of bytes logged.
 */
int logClientMessage(char *file, char *msg, int msgSize)
{
	int status = 0;
	int fd;
	int flags = O_CREAT | O_RDWR | O_APPEND;
	int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char *logHeader = "\n\n---------------------------  LOGGING CLIENT MESSAGE  ---------------------------\n";

	fd = open(file, flags, mode);
	if (fd > 0) {
		write(fd, logHeader, strlen(logHeader));
		status = write(fd, msg, msgSize);
		close(fd);
	}

	return status;
}

/**
 * Check if the file passed as argument exists *AND* is a 
 * regular file (i.e. not a directory or device).
 *
 * @param filename the file we are gonna check if exists.
 * @return 1 or 0, depending on whether the file exists or not.
 */
int file_exists(const char *filename)
{
	int ret = 0;
	struct stat stat_buf;

	ret = (stat(filename, &stat_buf) == 0 && S_ISREG (stat_buf.st_mode));

	return ret;
}



void handle(int sk)
{
	char request[1024], delims[] = " ";
	char *result = NULL;
	int i = 0, get;
	char c;
	
	char resourcePath[512];
	int nByte;
	HTTPResponse *resp = NULL;
	char responseBuf[8192];

	/* Read the request from the client. */
	while(read(sk, &c, 1) == 1 && c != '\n' && c != '\r' && i < sizeof(request) - 1) {
		request[i++] = c;
	}

	request[i] = '\0';

	result = strtok(request, delims);

	get = 0;	
	while(result != NULL) {
		get = (strcmp(result, "GET") == 0) ? 1 : get;
		if (get && strcmp(result, "GET") != 0) {
			strcpy(resourcePath, result);
			strcpy(request, resourcePath);
			break;	
		}
		result = strtok(NULL, delims);
	}

	printf("request: [%s]\n", request);

	sprintf(resourcePath, "%s%s", ROOT, request);
	printf("resourcePath: [%s]\n", resourcePath);

	if (!file_exists(resourcePath)) {
		for (i = 0; i < INDEXES_COUNT; i++) {
			memset(resourcePath, 0, sizeof(resourcePath));
			sprintf(resourcePath, "%s%s%s", ROOT, request, indexes[i]);
			printf("resourcePath: [%s]\n", resourcePath);
			if (file_exists(resourcePath)) {
				break;
			}
		}
	}

	if (!file_exists(resourcePath)) {
		resp = createResponse("error_pages/not_found.htm");
	}
	else {
		resp = createResponse(resourcePath);
	}
	
	logClientMessage(LOG_FILE, request, i);

/*	memset(resourcePath, 0, sizeof(resourcePath));
	strcat(resourcePath, ROOT);
	//strcat(resourcePath, request);
	strcat(resourcePath, "/index.htm");
*/
	printf("resourcePath: %s\n", resourcePath);

	// HTTP Response
//	resp = createResponse(resourcePath);
	nByte = serializeResponse(resp, (char*)responseBuf, sizeof(responseBuf)); //TODO: Treat the case nByte > sizeof(responseBuf)
	write(sk, responseBuf, nByte);

	while((nByte = read(resp->fdEntityBody, responseBuf, sizeof(responseBuf))) > 0) {
		printf("%d\n", write(sk, responseBuf, nByte));
	}

	destroyResponse(resp);
	close(sk);
}


int get_listener(int port)
{
	int s;
	struct sockaddr_in sin;

	/* Allocate a TCP/IP socket. */
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	/* Listen for connections on an arbitrary port */
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if ((bind(s, (struct sockaddr *) &sin, sizeof(sin))) == -1) {
		perror("bind");
		exit(2);
	}

	if (listen(s, 128) == -1) {
		perror("listen");
		exit(3);
	}

	return s;
}

void spawn_server()
{
	int s, sk, addrlen, status;
	struct sockaddr_in from;

	s = get_listener(PORT);

	for (;;) {
		printf("Waiting for new connections ...\n");
		/* Wait for a new connection from a client. */
		addrlen = sizeof(from);
		sk = accept(s, (struct sockaddr *) &from, &addrlen);

		if (sk == -1) {
                        perror("accept");
		}
		else {
			/* Create a new child process. */
			if(fork() == 0) {
				/* Perform the client's request in the child process. */
				//handle(sk);
				handle(sk);
				close(sk);
				exit(0);
			}

			/* Collect dead children, but don't wait for them. */
			waitpid(-1, &status, WNOHANG);
		}
	}
}

int main()
{
	spawn_server();
	return 0;
}

