//
// Created by jiaha on 5/28/2021.
//

#ifndef HW7_PARALLELRASTER_H
#define HW7_PARALLELRASTER_H

#include "Raster.h"
#include "ArrayRaster.h"
#include <thread>

class ParallelRaster: public Raster{
private:
    int wid;
    int hei;
    int numOfthreads;
    std::vector<std::vector<int>> raster;
    void parallet_compute(Raytracer& rt, int, int);
public:
    ParallelRaster(int width, int height, int threads);
    void render(Raytracer&);
    int at(int, int);
    int width();
    int height();
};


#endif //HW7_PARALLELRASTER_H
