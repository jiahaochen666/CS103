#include <iostream>
#include <queue>
#include <set>
#include "ChessNode.hpp"

#define N 8

std::vector<std::pair<int, int>> knight_moves = {{2,  -1},
                                                 {2,  1},
                                                 {-2, 1},
                                                 {-2, -1},
                                                 {1,  2},
                                                 {1,  -2},
                                                 {-1, 2},
                                                 {-1, -2}};

bool is_visited(std::set<ChessNode> &visited, ChessNode current) {
    for (auto &v: visited) {
        if (v == current)
            return true;
    }
    return false;
}

int shortest_steps(ChessNode src, ChessNode dest) {
    std::set<ChessNode> visited;
    std::queue<ChessNode> next_steps;
    next_steps.push(src);
    visited.insert(src);
    while (!next_steps.empty()) {
        ChessNode current_steps = next_steps.front();
        next_steps.pop();
        if (current_steps == dest) {
            return current_steps.d;
        }
        std::set<ChessNode> possible_steps = current_steps.possible_next(knight_moves);
        for (auto &next: possible_steps) {
            if (!is_visited(visited, next)) {
                next_steps.push(next);
                visited.insert(next);
            }
        }
    }

    return -1;
}

int main() {
    int sx, sy, dx, dy;
    std::cin >> sx >> sy >> dx >> dy;
    std::cout << shortest_steps({sx, sy}, {dx, dy}) << std::endl;
    return 0;
}
