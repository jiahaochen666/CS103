//
// Created by jiaha on 4/28/2021.
//

#ifndef HW4_PGMOUT_H
#define HW4_PGMOUT_H

#include <vector>
#include <iostream>

class PGMOut {
public:
    PGMOut() = default;
    static void save(const std::vector<std::vector<int>>&);
};


#endif //HW4_PGMOUT_H
