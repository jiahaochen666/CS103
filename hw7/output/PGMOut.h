#ifndef RAYTRACER_PGMOUT_H
#define RAYTRACER_PGMOUT_H

#include "../raster/Raster.h"

class PGMOut {
public:
    void save(Raster*) const noexcept;
};

#endif
