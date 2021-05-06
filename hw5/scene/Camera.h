//
// Created by jiaha on 5/4/2021.
//

#ifndef HW4_CAMERA_H
#define HW4_CAMERA_H

#include "primitive/Primitive.h"

class Camera {
private:
    Point cam_pos{};
    Vector view_vector{};
    Vector view_up{};
    Vector view_right{};
public:
    Camera() = default;
    Camera(Point, Point, double, double);
    Camera(const Camera&);
    Ray get_ray(double, double);
};


#endif //HW4_CAMERA_H
