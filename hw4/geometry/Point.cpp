//
// Created by jiaha on 4/28/2021.
//

#include "Point.h"

Vector Point::operator-(Point &other) {
    return Vector{
            this->pos_x - other.pos_x,
            this->pos_y - other.pos_y,
            this->pos_z - other.pos_z
    };
}

Vector Point::get_ray_direction(double x, double y) const {
    return Vector{
        x - this->pos_x,
        y - this->pos_y,
        -this->pos_z
    };
}
