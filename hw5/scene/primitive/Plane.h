//
// Created by jiaha on 5/4/2021.
//

#ifndef HW4_PLANE_H
#define HW4_PLANE_H

#include "Primitive.h"

class Plane: public Primitive {
private:
    Vector normal_vector;
    double distance;
public:
    Plane(Point, Vector);
    std::vector<Intersection> intersections(Ray &ray) override;
};


#endif //HW4_PLANE_H
