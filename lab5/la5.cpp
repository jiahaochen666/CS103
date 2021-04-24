#include <iostream>

#include "Vector.hpp"



int main() {
    Vector<int> num(64);
    Vector<char> alpha(64);
    char c;

    while(std::cin >> c) {
        if(c >= 48 && c <=57) {
            num.insert(c - 48);
        } else {
            alpha.insert(c);
        }
    }

    for(int i = 0; i < num.size(); ++i) {
        std::cout << num[i] << std::endl;
    }

    for(int j = 0; j < alpha.size(); ++j) {
        std::cout << alpha[j] << std::endl;
    }
}

