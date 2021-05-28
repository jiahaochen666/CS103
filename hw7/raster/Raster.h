//
// Created by jiaha on 5/28/2021.
//

#ifndef HW7_RASTER_H
#define HW7_RASTER_H

#include "../tracer/Raytracer.h"

namespace {
    class Viewport {
        double x_factor_;
        double x_shift_;
        double y_factor_;
        double y_shift_;

    public:
        Viewport(int x_resolution, int y_resolution) noexcept:
                x_factor_{x_resolution == 1 ? 1. : 2. / x_resolution},
                x_shift_{1. - 1. / x_resolution},
                y_factor_{y_resolution == 1 ? 1. : 2. / y_resolution},
                y_shift_{1 - 1. / y_resolution} {
        }

        [[nodiscard]] std::pair<double, double> convert_pixels(int x, int y) const noexcept {
            return {x * x_factor_ - x_shift_, y * y_factor_ - y_shift_};
        }
    };
}

class Raster {
public:
    virtual void render(Raytracer&) = 0;
    virtual int at(int, int) = 0;
    virtual int width() = 0;
    virtual int height() = 0;
    virtual ~Raster() = default;
};


#endif //HW7_RASTER_H
