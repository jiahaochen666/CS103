//
// Created by jiaha on 4/28/2021.
//

#include "Raytracer.h"

std::vector<std::vector<int>> Raytracer::to_raster(int resolution) {
    std::cout << "P2\n"; // Magic PBM bytes
    std::cout << resolution << ' ' << resolution << '\n';
    std::cout << "255\n"; // This means that 1 should be displayed as white.
// Our viewport is in the range [-1;1] in both x in y direction. To convert a pixel into a viewport
    // coordinate, we need to scale it first by (coordinate * 2 / resolution). However, if the resolution
    // is for example 2x2, we don't want rays at the four corners (-1;-1), (-1;1), (1;-1) and (1;1). If the
    // viewport is divided by for pixels, is is a square subdivided by four squares. We want to cast a ray
    // through the middle of each square:
    //
    //  (-1;1) x-+-x (1;1)
    //         |o|o|
    //         +-+-+
    //         |o|o|
    // (-1;-1) x-+-x (-1;1)
    //
    // In this 2x2 viewport, the 'x' are the corners, and the 'o' are the rays we want to trace. To center
    // them, we need to add to them 1/resolution. In the case of resolution=2, this is 0.5.
    //
    // So to scale we do do the same thing for the and y value. For resolution=4, the desired rays are at
    // the coordinates {-0.75, -0.25, 0.25, 0.75} in both x and y direction. The pixel coordinates are in
    // the interval [0;3]. We multiply this with 2/resolution, which scales this value to interval [0;1.5].
    // now we subtract 1 and add 1/resolution to scale it to the interval [-0.75;0.75]. This works for odd
    // and even numbers, except 1, which needs special case handling.
    double viewport_scale_factor{resolution == 1 ? 1 : 2. / resolution};
    double viewport_shift{1 - 1. / resolution};

    // The camera is located at (x=0;y=0;z=5).
    Point camera{0, 0, 5};

    // And there is a sphere at (0;0;-5) with radius 1.
    int radius = 1;
    Sphere sphere{{0, 0, -5}, radius};
    std::vector<std::vector<int>> out(resolution, std::vector<int>(resolution, 0));

//     To compute intersections, consider this article:
//     http://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/
//     delta_{x,y,z} is the vector A-C
    for (int y_pixel = 0; y_pixel < resolution; ++y_pixel) {
        // To get the ray, we need the viewport coordinates. This is the y coordinate...
        double viewport_y_coordinate{y_pixel * viewport_scale_factor - viewport_shift};
        for (int x_pixel = 0; x_pixel < resolution; ++x_pixel) {
            // ... and the x coordinate.

            double viewport_x_coordinate{x_pixel * viewport_scale_factor - viewport_shift};

            // Now we get the vector from the camera to the viewport.
            Vector ray_direction = camera.get_ray_direction(viewport_x_coordinate, viewport_y_coordinate);
            // And we want to make sure to normalize the ray we want to trace to a length of 1, because this will
            // simplify many computations.
            ray_direction.normalize();

            Ray ray{camera, ray_direction};

            std::vector<double> intersect = sphere.intersections(ray);
            // Now we can use the formula from the link to calculate b and c. Note that we can omit a, because
            // ray.dot(ray)=1. This is, because we normalized it.

            // If there is an intersection, the discriminant >= 0, so we emit 1, to indicate full brightness, otherwise
            // 0 to indicate black.

            if (intersect[0] >= 0 && intersect[1] >= 0) {
                double smallest = intersect[0] < intersect[1] ? intersect[0] : intersect[1];
                double brightness = 10 - smallest;
                if (brightness < 0) brightness = 0;
                int pixel_brightness = static_cast<int>(brightness * 255);
                out[x_pixel][y_pixel] = pixel_brightness;
            }
        }
    }
    return out;
}
