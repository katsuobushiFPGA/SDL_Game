subdirs := src
.PHONY: all
all :
	(cd src; make)
.PHONY: test
test:
	(cd test;make)

clean:
	(cd src; make clean)

install:
	(cd src; make install)

