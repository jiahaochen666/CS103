CXXFLAGS = -g -pedantic -Wall -Wextra -std=c++17 -fPIC
LDFLAGS = -g

SRCS_CPP = geometry/Point.cpp geometry/Ray.cpp geometry/Vector.cpp image/PGMOut.cpp scene/primitive/Sphere.cpp scene/primitive/Primitive.cpp scene/primitive/Plane.cpp scene/primitive/Intersection.cpp scene/Camera.cpp scene/Scene.cpp tracer/Raytracer.cpp
SRCS_HPP = $(SRCS_CPP:.cpp=.hpp)
OBJS = main.o $(SRCS_CPP:.cpp=.o)

.PHONY: all
all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): geometry/Point.h geometry/Ray.h geometry/Vector.h image/PGMOut.h scene/primitive/Sphere.h tracer/Raytracer.h scene/primitive/Intersection.h scene/primitive/Plane.h scene/primitive/Primitive.h scene/Camera.h scene/Scene.h

.PHONY: clean
clean:
	rm -f *.o a.out
