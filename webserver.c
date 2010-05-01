#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

/*================================= DEFINES ==================================*/
#define LOG_FILE	"log/http_requests.log"
#define PORT		12345
#define ROOT		"./web"

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


void handle(int sk)
{
	char request[1024], buf[8192];
	int i = 0, n, fd;
	char c;
	char resourcePath[512];

	/* Read the request (a file name) from the client. */
	while(read(sk, &c, 1) == 1 && c != '\n' && c != '\r' && i < sizeof(request) - 1) {
		request[i++] = c;
	}

	request[i] = '\0';
	
	logClientMessage(LOG_FILE, request, i);

	memset(resourcePath, 0, sizeof(resourcePath));
	strcat(resourcePath, ROOT);
	//strcat(resourcePath, request);
	strcat(resourcePath, "/index.htm");
	printf("resourcePath: %s\n", resourcePath);

	fd = open(resourcePath, 0);

	while((n = read(fd, buf, sizeof(buf))) > 0) {
		printf("%d\n", write(sk, buf, n));
	}

	close(fd);
	close(sk);
}

int get_listener(int port)
{
	int s;
	struct sockaddr_in sin;

	/* Allocate a TCP/IP socket. */
	s = socket(AF_INET, SOCK_STREAM, 0);

	/* Listen for connections on an arbitrary port */
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	bind(s, (struct sockaddr *) &sin, sizeof(sin));
	listen(s, 128);

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

		/* Create a new child process. */
		if(fork() == 0) {
			/* Perform the client's request in the child process. */
			handle(sk);
			exit(0);
		}

		close(sk);

		/* Collect dead children, but don't wait for them. */
		waitpid(-1, &status, WNOHANG);
	}
}

int main()
{
	spawn_server();
	return 0;
}

