//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_SPHERE_H
#define HW4_SPHERE_H

#include "Primitive.h"

class Sphere: public Primitive{
private:
    Point center;
    int radius;
public:
    Sphere(Point, int );
    std::vector<Intersection> intersections(Ray &ray) override;
};


#endif //HW4_SPHERE_H
