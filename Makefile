all:
	gcc webserver.c -o webserver
	cd test; make
clean:
	rm -rf webserver
