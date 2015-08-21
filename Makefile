#Makefile
CXX=g++
CXXFLAGS=-std=c++11
INSTALLPATH=/home/hiroto/bin/
TARGET=sdl_game
OBJFILE=game
COMPILE_FILES=*.cpp

all: *.o
	$(CXX) $(CXXFLAGS) -Wall -O2 -o $(OBJFILE) *.o -lSDL

*.o:
	$(CXX) -c $(COMPILE_FILES)

.PHONY: all
clean:
	$(RM) *.o
	$(RM) $(OBJFILE) $(objs)
	$(RM) $(INSTALLPATH)$(OBJFILE)

install: 
	     cp $(OBJFILE) $(INSTALLPATH)$(OBJFILE)
	
