#include "TypeInfo.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << TypeInfo<const char>().to_string() << '\n'
         << TypeInfo<const short int>().to_string() << '\n'
         << TypeInfo<const int>().to_string() << '\n'
         << TypeInfo<const long int>().to_string() << '\n';
    return 0;
}