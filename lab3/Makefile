CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++11
LDFLAGS = -g

SRCS_CPP = Airplane.cpp Automobile.cpp Fruit.cpp Garage.cpp la3.cpp Truck.cpp Vehicle.cpp
OBJS = $(SRCS_CPP:.cpp=.o)

.PHONY: all
all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): Airplane.hpp Automobile.hpp Fruit.hpp Garage.hpp Truck.hpp Vehicle.hpp

.PHONY: clean
clean:
	rm -f *.o a.out