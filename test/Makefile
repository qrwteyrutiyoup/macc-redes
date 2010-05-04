
all: clean test_http_header test_http_response

test_http_header: test_http_header.c ../http_header.c ../http_header.h
	gcc -g ../http_header.c test_http_header.c -o test_http_header

test_http_response: test_http_response.c ../http_response.c ../http_response.h ../http_header.c ../http_header.h
	gcc -g ../http_header.c ../http_response.c test_http_response.c -o test_http_response


clean:
	rm -rf *.o
	rm -rf test_http_header test_http_response

