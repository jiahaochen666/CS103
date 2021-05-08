//
// Created by jiaha on 5/4/2021.
//

#include "Camera.h"
#include "iostream"

Camera::Camera(Point pos, Point center, double height, double width) {
    this->cam_pos = pos;
    this->view_vector = center - pos;
    this->view_right = this->view_vector.cross({0, 1, 0}).normalize() * (width / 2);
    this->view_up = this->view_right.cross(this->view_vector).normalize() * (height / 2);
}

Ray Camera::get_ray(double horizon, double vertical) {
    //std::cout << view_right.pos_x << view_right.pos_y << view_right.pos_z << "\n";
    return Ray(this->cam_pos, (view_vector + this->view_right * horizon + this->view_up * vertical).normalize());
}
Camera::Camera(const Camera &other) {
    this->cam_pos = other.cam_pos;
    this->view_vector = other.view_vector;
    this->view_right = other.view_right;
    this->view_up = other.view_up;
}


