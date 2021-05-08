//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_POINT_H
#define HW4_POINT_H

#include "Vector.h"

struct Point {
    double pos_x, pos_y, pos_z;
    Vector operator-(Point other);
    Vector get_ray_direction(double x, double y) const;
    Point operator+(Vector other);
};


#endif //HW4_POINT_H
