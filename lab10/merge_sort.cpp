#include <vector>
#include "merge_sort.hpp"

void partition(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& arr) {
    p1.clear();
    p2.clear();

    int n = arr.size();
    int mid = n / 2;

    for (int i = 0; i < mid; ++i) {
        p1.push_back(arr[i]);
    }

    for (int j = mid; j < n; ++j) {
        p2.push_back(arr[j]);
    }
}


void merge(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& merged) {
    int n1 = p1.size();
    int n2 = p2.size();

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) {
        if (p1[i] <= p2[j]) {
            merged[i + j] = p1[i];
            ++i;
        }
        else {
            merged[i + j] = p2[j];
            ++j;
        }
    }

    while (i < n1) {
        merged[i + j] = p1[i];
        ++i;
    }

    while (j < n2) {
        merged[i + j] = p2[j];
        ++j;
    }
}