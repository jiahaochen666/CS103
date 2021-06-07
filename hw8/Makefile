CXXFLAGS = -g -Wno-unused-variable -std=c++17
# CXXFLAGS = -g -Wall -Wextra -Wno-unused-variable -std=c++17
LDFLAGS = -g

SRCS_CPP = hw8.cpp
OBJS = $(SRCS_CPP:.cpp=.o)

.PHONY: all
all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS):

.PHONY: clean
clean:
	rm -f *.o a.out
