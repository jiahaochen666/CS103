#include "Functional.hpp"
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<std::pair<std::string, int>> in;
    for (int i = 0; i < 100; ++i)
    {
        in.emplace_back(to_string(i), i * 2);
    }
    vector<string> vec1;
    vector<int> vec2;
    unzip(in.begin(), in.end(), std::back_inserter(vec1), std::back_inserter(vec2));
    for (int i = 0; i < 100; ++i)
    {
        cout << vec1[i] << ' ' << vec2[i] << '\n';
    }
    return 0;
}