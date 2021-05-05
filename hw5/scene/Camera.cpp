//
// Created by jiaha on 5/4/2021.
//

#include "Camera.h"

Camera::Camera(Point pos, Point center, double height, double width) {
    this->cam_pos = pos;
    this->view_vector = pos - center;
    this->view_right = this->view_vector.cross({0, 1, 0}) * (width / 2);
    this->view_up = this->view_right.cross(this->view_vector) * (height / 2);
}

Ray Camera::get_ray(double horizon, double vertical) {
    return Ray(this->cam_pos, view_vector + this->view_right * horizon + this->view_up * vertical);
}


