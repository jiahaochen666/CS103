//
// Created by jiaha on 5/4/2021.
//

#ifndef HW4_SCENE_H
#define HW4_SCENE_H

#include <iostream>
#include <fstream>
#include "Camera.h"
#include <sstream>
#include "primitive/Sphere.h"
#include "primitive/Plane.h"


class Scene {
private:
    std::ifstream file;
    std::vector<double> get_three(std::istringstream& ss);
public:
    Scene() = default;
    Camera camera;
    std::vector<Primitive*> objects;
    Scene(std::string path);
    std::vector<Intersection> find_intersection(Ray& ray);
    ~Scene();
};


#endif //HW4_SCENE_H
