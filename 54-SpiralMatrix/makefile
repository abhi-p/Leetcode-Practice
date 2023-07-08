CXX=g++

CPPFLAGS= -g -std=c++11 -Wall -pedantic
LDFLAGS= #-g $(shell root-config --ldflags)
LDLIBS= #$(shell root-config --libs)

SRCS=spiralMatrix.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: spiralMatrix

spiralMatrix: $(OBJS)
	$(CXX) $(LDFLAGS) -o spiralMatrix $(OBJS) $(LDLIBS)

spiralMatrix.o: spiralMatrix.cpp

clean:
	rm -rf $(OBJS) spiralMatrix
