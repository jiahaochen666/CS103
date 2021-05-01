//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_RAYTRACER_H
#define HW4_RAYTRACER_H

#include "../image/PGMOut.h"
#include "../scene/Sphere.h"


class Raytracer {
public:
    Raytracer() = default;
    std::vector<std::vector<int>> to_raster(int resolution);
};


#endif //HW4_RAYTRACER_H
