#Makefile
CXX = g++
CXXFLAGS=-std=c++11 -Wall
LDLIBS = -lcppunit
LDFLAGS=-I/usr/include -L/usr/lib
OBJS = Test.o

all : test

test : $(OBJS)
	   $(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

%.o  : %.cpp
	   $(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

Test.o:Test.cpp

clean:
	   rm *.o $(EXEC)
