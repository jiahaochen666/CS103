//
// Created by jiaha on 5/4/2021.
//

#include "Plane.h"
#include "iostream"

Plane::Plane(Point point, Vector vector) {
    this->normal_vector = vector.normalize();
    Vector plane_vector = point - Point{0, 0, 0};
    this->distance = -(plane_vector.dot(this->normal_vector));
}

std::vector<Intersection> Plane::intersections(Ray &ray) {
    double vd = ray.direction.dot(this->normal_vector);
    if(vd == 0)
        return {};
    double dist = -(this->normal_vector.dot(ray.start - Point{0,0,0}) + this->distance) / vd;
    if(dist < 0)
        return {};
    Point intersection = ray.start + ray.direction * dist;
    return std::vector<Intersection>{Intersection{this, dist, intersection}};
}
