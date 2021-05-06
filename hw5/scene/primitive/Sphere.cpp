//
// Created by jiaha on 4/28/2021.
//

#include <iostream>
#include "Sphere.h"

Sphere::Sphere(Point center, int radius) {
    this->center = center;
    this->radius = radius;
}

std::vector<Intersection> Sphere::intersections(Ray &ray) {
    Vector delta = ray.start - this->center;
    double b = delta.dot(ray.direction) * 2;
    double c = delta.dot(delta) - this->radius * this->radius;
    double discriminant{b * b - 4 * c};
    double distance_1 = -1;
    double distance_2 = -1;
    if (discriminant >= 0) {
        distance_1 = (-b + sqrt(discriminant)) / 2;
        distance_2 = (-b - sqrt(discriminant)) / 2;
    }
    std::vector<Intersection> out;
    if (distance_1 > 0) {
        Point intersection1 = ray.start + ray.direction * distance_1;
        out.push_back(Intersection{this, distance_1, intersection1});
    }
    if (distance_2 > 0) {
        Point intersection2 = ray.start + ray.direction * distance_2;
        out.push_back(Intersection{this, distance_2, intersection2});
    }
    return out;
}