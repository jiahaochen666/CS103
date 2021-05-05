CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++17 -fPIC
LDFLAGS = -g

SRCS_CPP = geometry/Point.cpp geometry/Ray.cpp geometry/Vector.cpp image/PGMOut.cpp scene/Sphere.cpp tracer/Raytracer.cpp
SRCS_HPP = $(SRCS_CPP:.cpp=.hpp)
OBJS = main.o $(SRCS_CPP:.cpp=.o)

.PHONY: all
all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): geometry/Point.h geometry/Ray.h geometry/Vector.h image/PGMOut.h scene/primitive/Sphere.h tracer/Raytracer.h

.PHONY: clean
clean:
	rm -f *.o a.out
