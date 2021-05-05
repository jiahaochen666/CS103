//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_RAY_H
#define HW4_RAY_H

#include "Point.h"
#include "Vector.h"
class Ray {
public:
    Point start{};
    Vector direction{};
public:
    Ray(Point, Vector);
};


#endif //HW4_RAY_H
