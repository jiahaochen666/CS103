//
// Created by jiaha on 5/4/2021.
//

#ifndef HW4_PRIMITIVE_H
#define HW4_PRIMITIVE_H

#include "../../geometry/Point.h"
#include "../../geometry/Ray.h"
#include "../../geometry/Vector.h"
#include "Intersection.h"
#include <vector>

struct Intersection;

class Primitive {
public:
    virtual std::vector<Intersection> intersections(Ray& ray) = 0;
};


#endif //HW4_PRIMITIVE_H
