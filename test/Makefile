#Makefile
CXX = g++
CXXFLAGS=-std=c++11 -Wall
LDLIBS = -lcppunit -lSDL -lSDL_image
INCLUDE= -I../src/include
OBJS = Test.o

all : test

test : $(OBJS)
	   $(CXX) $^ -o $@ $(INCLUDE) $(LDLIBS)

%.o  : %.cpp
	   $(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

Test.o:Test.cpp

clean:
	   rm *.o $(EXEC)
	   rm test
