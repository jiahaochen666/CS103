//
// Created by jiaha on 4/28/2021.
//

#include "Vector.h"

void Vector::normalize() {
    double ray_length = sqrt(this->pos_x * this->pos_x +
                             this->pos_y * this->pos_y +
                             this->pos_z * this->pos_z);
    this->pos_x /= ray_length;
    this->pos_y /= ray_length;
    this->pos_z /= ray_length;
}

double Vector::dot(Vector other) {
    return this->pos_x * other.pos_x + this->pos_y * other.pos_y + this->pos_z * other.pos_z;
}

Vector Vector::operator*(double d) const {
    return Vector{this->pos_x * d, this->pos_y * d, this->pos_z * d};
}

Vector Vector::cross(Vector other) {
    return Vector{this->pos_y * other.pos_z - this->pos_z * other.pos_y,
                  this->pos_x * other.pos_z - this->pos_z - other.pos_x,
                  this->pos_x * other.pos_y - this->pos_y * other.pos_x};
}

Vector Vector::operator+(Vector other) const {
    return Vector{this->pos_x + other.pos_x,
                  this->pos_y + other.pos_y,
                  this->pos_z + other.pos_z};
}
