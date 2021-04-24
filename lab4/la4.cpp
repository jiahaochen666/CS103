#include <cstdlib>
#include <iostream>

#include "StreetMap.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        return -1;
    }

    int n = atoi(argv[1]);
    int l, r;
    srand(n);
    StreetMap maps[3];


    for (int i = 0; i < n; ++i) {
        maps[0].insert(i);
    }

    for (int i = 0; i < n; ++i) {
        l = rand() % n;
        r = rand() % n;
        maps[0].connect_left(i, l);
        maps[0].connect_right(i, r);
    }


    maps[0].restart();
    maps[1] = maps[0];
    maps[2] = maps[1];

    // === YOUR CODE HERE ===
    std::cout << maps[0] << std::endl;
    std::cout << maps[1] << std::endl;
    std::cout << maps[2] << std::endl;
    char cmd;
    while(std::cin >> cmd){
        if (cmd == 'L'){
            maps[0].walk();
            maps[1].turn_left();
            maps[2].turn_right();
        }
        else if(cmd == 'R'){
            maps[0].walk();
            maps[1].turn_right();
            maps[2].turn_left();
        }
        else if (cmd == 'Z'){
            maps[0].restart();
            maps[1].restart();
            maps[2].restart();
        }
        std::cout << maps[0] << std::endl;
        std::cout << maps[1] << std::endl;
        std::cout << maps[2] << std::endl;
    }

    // ======================

    return 0;
}
