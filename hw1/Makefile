CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++11
LDFLAGS = -g

SRCS_CPP = LinkedList.cpp HashMap.cpp main.cpp
OBJS = $(SRCS_CPP:.cpp=.o)

.PHONY: all
all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): HashMap.hpp LinkedList.hpp

.PHONY: clean
clean:
	rm -f *.o a.out