//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_VECTOR_H
#define HW4_VECTOR_H
#include <cmath>

struct Vector {
    double pos_x, pos_y, pos_z;
    Vector normalize();
    double dot(Vector);
    Vector operator*(double) const;
    Vector operator+(Vector) const;
    Vector cross(Vector);
};


#endif //HW4_VECTOR_H
