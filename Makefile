all:
	gcc *.c -o webserver
	cd test; make
clean:
	rm -rf webserver
