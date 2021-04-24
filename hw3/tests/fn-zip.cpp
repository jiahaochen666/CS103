#include "Functional.hpp"
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec1(100);
    vector<int> vec2(200);
    iota(vec1.begin(), vec1.end(), 1);
    iota(vec2.begin(), vec2.end(), 2);
    vector<std::pair<int, int>> out;
    zip(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(out));
    for (auto [a, b] : out)
    {
        cout << a << ' ' << b << '\n';
    }
    return 0;
}