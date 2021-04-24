#include "TypeInfo.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << TypeInfo<char>().to_string() << '\n'
         << TypeInfo<short int[5]>().to_string() << '\n'
         << TypeInfo<int[5][10]>().to_string() << '\n'
         << TypeInfo<long int[5][10][20]>().to_string() << '\n';
    return 0;
}