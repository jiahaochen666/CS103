CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++17
LDFLAGS = -g

SRCS_CPP = la5.cpp
OBJS = $(SRCS_CPP:.cpp=.o)

.PHONY: all
all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): Vector.hpp

.PHONY: clean
clean:
	rm -f *.o a.out