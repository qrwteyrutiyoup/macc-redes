
all: test_http_header

test_http_header: test_http_header.c ../http_header.c ../http_header.h
	gcc ../http_header.c test_http_header.c -o test_http_header

clean:
	rm -rf *.o
	rm -rf test_http_header

