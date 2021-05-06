//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_RAYTRACER_H
#define HW4_RAYTRACER_H

#include "../image/PGMOut.h"
#include "../scene/Camera.h"
#include "../scene/Scene.h"


class Raytracer {
private:
    Scene* scene;
public:
    explicit Raytracer(Scene&& scene);
    std::vector<std::vector<int>> to_raster(int resolution);
};


#endif //HW4_RAYTRACER_H
