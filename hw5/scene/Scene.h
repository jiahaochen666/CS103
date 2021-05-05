//
// Created by jiaha on 5/4/2021.
//

#ifndef HW4_SCENE_H
#define HW4_SCENE_H

#include <iostream>
#include <fstream>
#include "Camera.h"
#include <sstream>


class Scene {
private:
    std::ifstream file;
public:
    Camera camera;
    std::vector<Primitive> objects;
    explicit Scene(std::string path);
};


#endif //HW4_SCENE_H
