//
// Created by jiaha on 5/27/2021.
//

#include "ArrayRaster.h"

ArrayRaster::ArrayRaster(int width, int height) {
    this->wid = width;
    this->hei = height;
    this->raster = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}


int ArrayRaster::at(int x, int y) {
    return this->raster[x][y];
}

void ArrayRaster::render(Raytracer &rt) {
    const Viewport vp{this->hei, this->wid};
    for (int y_pixel = this->wid - 1; y_pixel >= 0; --y_pixel) {
        for (int x_pixel = 0; x_pixel < this->hei; ++x_pixel) {
            auto[x, y] = vp.convert_pixels(x_pixel, y_pixel);
            int brightness{static_cast<int>(rt.trace_primary(x, y))};
            raster[y_pixel][x_pixel] = brightness;
        }
    }
}

int ArrayRaster::width(){
    return this->wid;
}

int ArrayRaster::height(){
    return this->hei;
}