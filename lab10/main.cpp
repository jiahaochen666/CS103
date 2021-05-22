#include <iostream>
#include <thread>
#include <vector>
#include "merge_sort.hpp"


void merge_sort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        std::vector<int> p1;
        std::vector<int> p2;
        partition(p1, p2, arr);
        std::thread first(merge_sort, std::ref(p1));
        std::thread second(merge_sort, std::ref(p2));
        first.join();
        second.join();
        merge(p1, p2, arr);
    }
}



int main() {
    std::vector<int> arr;
    int i;
    while(std::cin >> i) {
        arr.push_back(i);
    }
    std::thread this_thread(merge_sort, std::ref(arr));
    this_thread.join();
    for(const auto& a: arr) {
        std::cout << a << std::endl;
    }
}
