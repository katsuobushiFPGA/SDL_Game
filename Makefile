subdirs := src
.PHONY: all
all :
	(cd src; make)
.PHONY: test
test:
	(cd test;make)
.PHONY: clean
clean:
	(cd src; make clean)
.PHONY: install
install:
	(cd src; make install)

