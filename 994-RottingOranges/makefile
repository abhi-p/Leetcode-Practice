CPP=g++

CPPFLAGS = -g -Wall -std=c++11 -pedantic

SRCS = rottingOranges.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
EXE = $(subst .cpp, ,$(SRCS))

all: $(EXE)

$(EXE): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(EXE) $(OBJS)

$(OBJS):
	$(CPP) $(CPPFLAGS) -c -o $(OBJS) $(SRCS)

clean:
	rm -rf $(OBJS) $(EXE)
