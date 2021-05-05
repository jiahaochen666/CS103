#include <cerrno>
#include <cstdlib>
#include "tracer/Raytracer.h"

int main(int argc, char *argv[]) {
    int resolution = strtol(argv[1], nullptr, 0);
    Raytracer raytracer;
    PGMOut::save(raytracer.to_raster(resolution));
    return 0;
}