#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void handle(int sk)
{
	char request[1024], buf[8192];
	int i = 0, n, fd;
	char c;

	/* Read the request (a file name) from the client. */
	while(read(sk, &c, 1) == 1 && c != '\n' && c != '\r' && i < sizeof(request) - 1) {
		request[i++] = c;
	}

	request[i] = '\0';
	fd = open(request, 0);

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

	s = get_listener(12345);

	for (;;) {
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

