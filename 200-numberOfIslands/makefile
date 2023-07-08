CXX=g++

CPPFLAGS= -g -std=c++11 -Wall -pedantic
LDFLAGS= #-g $(shell root-config --ldflags)
LDLIBS= #$(shell root-config --libs)

SRCS=numberOfIslands.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: numberOfIslands

numberOfIslands: $(OBJS)
	$(CXX) $(LDFLAGS) -o numberOfIslands $(OBJS) $(LDLIBS)

numberOfIslands.o: numberOfIslands.cpp

clean:
	rm -rf $(OBJS) numberOfIslands
