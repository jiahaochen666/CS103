//
// Created by jiaha on 4/28/2021.
//

#include "PGMOut.h"

void PGMOut::save(const std::vector<std::vector<int>>& array_2D) {
    for (auto &v : array_2D){
        for (auto &i: v){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}
