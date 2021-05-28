//
// Created by jiaha on 5/27/2021.
//

#ifndef HW7_ARRAYRASTER_H
#define HW7_ARRAYRASTER_H

#include "Raster.h"

class ArrayRaster:  public Raster{
private:
    int wid;
    int hei;
    std::vector<std::vector<int>> raster;
public:
    ArrayRaster(int width, int height);
    void render(Raytracer& rt);
    int at(int x, int y);
    int width();
    int height();
};


#endif //HW7_ARRAYRASTER_H
