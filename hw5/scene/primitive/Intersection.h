//
// Created by jiaha on 5/4/2021.
//

#ifndef HW4_INTERSECTION_H
#define HW4_INTERSECTION_H

#include "Primitive.h"

struct Intersection {
    Primitive* primitive;
    double distance;
    Point intersection_point;
};


#endif //HW4_INTERSECTION_H
