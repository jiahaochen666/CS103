#include "output/PGMOut.h"
#include "tracer/Raytracer.h"
#include "raster/ArrayRaster.h"
#include "raster/ParallelRaster.h"
#include <cstdlib>

using namespace std;

int main(int, char *argv[]) {
    Scene scene{argv[1]};
    int resolution = static_cast<int>(strtol(argv[2], nullptr, 10));
    Raster* arr = new ParallelRaster{resolution, resolution, 4};
    Raytracer raytracer{move(scene)};
    arr->render(raytracer);
    PGMOut().save(arr);
    delete arr;
    return 0;
}