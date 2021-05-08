#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Plant.hpp"


int main() {
    std::vector<std::vector<Plant>> garden;
    std::string name;
    int start, end;

    std::vector<Plant> temp;
    while (std::cin >> name >> start >> end) {
        // Add plant to min-heap
        temp.emplace_back(name, start, end);
        std::push_heap(temp.begin(), temp.end(), [](Plant &a, Plant &b) { return a > b; });
    }
    //std::make_heap(temp.begin(), temp.end());

    // Schedule each plant into a "row" of the garden
    // by continuosly popping the min of the heap
    while (!temp.empty()) {
        Plant current = temp.front();
        if (garden.empty()) {
            garden.push_back(std::vector<Plant>{current});
        } else {
            int counter = 0;
            for (auto &v: garden) {
                if (v[v.size() - 1].end <= current.start) {
                    v.push_back(current);
                    break;
                }
                counter++;
            }
            if (counter == garden.size())
                garden.push_back(std::vector<Plant>{current});
        }
        std::pop_heap(temp.begin(), temp.end(), [](Plant &a, Plant &b) { return a > b; });
        temp.pop_back();
    }


    for (auto row : garden) {
        for (auto p : row) {
            std::cout << p << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
