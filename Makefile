all: td.c
	cc -o td td.c -lncurses
	nano td1/DEBIAN/control
	cp ./td ./td1/usr/bin/
	dpkg -b td1
clean:
	rm -rf td
	rm -rf td1.deb
	rm -rf ./td1/usr/bin/td
