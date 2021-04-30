//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_SPHERE_H
#define HW4_SPHERE_H

#include "../geometry/Point.h"
#include "../geometry/Ray.h"
#include "../geometry/Vector.h"

class Sphere {
private:
    Point center;
    double radius;
public:
    Vector intersections(Ray ray);
};


#endif //HW4_SPHERE_H
