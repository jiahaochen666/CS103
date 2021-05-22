CXXFLAGS = -g -pthread -pedantic -Wall -Wextra -std=c++17
LDFLAGS = -g -pthread

SRCS_CPP = main.cpp merge_sort.cpp
OBJS = $(SRCS_CPP:.cpp=.o)

.PHONY: all
all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): merge_sort.hpp

.PHONY: clean
clean:
	rm -f *.o a.out