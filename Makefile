subdirs := src
.PHONY: all
all :
	(cd src; make)

clean:
	(cd src; make clean)

install:
	(cd src; make install)

