//
// Created by jiaha on 5/28/2021.
//

#include "ParallelRaster.h"

ParallelRaster::ParallelRaster(int width, int height, int threads){
    this->wid = width;
    this->hei = height;
    this->numOfthreads = threads;
    this->raster = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}


void ParallelRaster::parallet_compute(Raytracer &rt, int start, int end) {
    const Viewport vp{this->hei, this->wid};

    for (int y_pixel = this->wid - 1; y_pixel >= 0; --y_pixel) {
        for (int x_pixel = start; x_pixel < end; ++x_pixel) {
            auto[x, y] = vp.convert_pixels(x_pixel, y_pixel);
            int brightness{static_cast<int>(rt.trace_primary(x, y))};
            raster[y_pixel][x_pixel] = brightness;
        }
    }
}

void ParallelRaster::render(Raytracer &rt) {
    std::vector<std::thread> threads;
    for (int i = 0;i < numOfthreads; i++){
        int start = hei / numOfthreads * i;
        int end = start + hei / numOfthreads;
        if (i == numOfthreads - 1)
            end = hei;
        threads.emplace_back(&ParallelRaster::parallet_compute, this, std::ref(rt), start, end);
    }
    for (int i = 0; i < numOfthreads; i++)
        threads[i].join();
}

int ParallelRaster::at(int x, int y) {
    return raster[x][y];
}

int ParallelRaster::width() {
    return this->wid;
}

int ParallelRaster::height() {
    return this->hei;
}

