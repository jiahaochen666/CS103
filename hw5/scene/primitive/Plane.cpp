//
// Created by jiaha on 5/4/2021.
//

#include "Plane.h"

Plane::Plane(Point point, Vector vector) {
    this->point = point;
    this->normal_vector = vector;
    this->distance = -((Point{0, 0 , 0} - this->point).dot(this->normal_vector));
}

std::vector<Intersection> Plane::intersections(Ray &ray) {
    double vd = ray.direction.dot(this->normal_vector);
    if(vd == 0)
        return {};
    double dist = -(this->normal_vector.dot(Point{0,0,0} - ray.start) + this->distance) / vd;
    Point intersection = ray.start + ray.direction * dist;
    return std::vector<Intersection>{Intersection{this, dist, intersection}};
}
