#include <cerrno>
#include <cstdlib>
#include "tracer/Raytracer.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        Scene scene{argv[1]};
        int resolution = static_cast<int>(strtol(argv[2], nullptr, 10));
        Raytracer raytracer{std::move(scene)};
        PGMOut::save(raytracer.to_raster(resolution));
    }
    return 0;
}