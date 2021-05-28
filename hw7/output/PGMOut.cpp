#include "PGMOut.h"
#include <iostream>

using namespace std;

void PGMOut::save(Raster* raster) const noexcept {
    cout << "P2\n";
    cout << raster->width() << ' ' << raster->height() << '\n';
    cout << "255\n";
    for (int  i = raster->height() - 1; i >= 0; --i) {
        for (int j = 0; j < raster->width(); j++) {
            cout << raster->at(i, j) << ' ';
        }
        cout << '\n';
    }
}
