//
// Created by jiaha on 4/28/2021.
//

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
    Point intersection1 = ray.start + ray.direction * distance_1;
    Point intersection2 = ray.start + ray.direction * distance_2;
    return std::vector<Intersection>{Intersection{*this, distance_1, intersection1}, Intersection{*this, distance_2, intersection2}};
}