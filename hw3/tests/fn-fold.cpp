#include "Functional.hpp"
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec(100);
    iota(vec.begin(), vec.end(), 1);
    cout << fold_left(vec.begin(), vec.end(), 5, [](int a, int b) { return a + b; }) << '\n';
    cout << fold_left(vec.begin(), vec.begin() + 10, -2, [](int a, int b) { return a * b; }) << '\n';
    return 0;
}