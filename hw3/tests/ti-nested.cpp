#include "TypeInfo.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << TypeInfo<char *&>().to_string() << '\n'
         << TypeInfo<short int const *const>().to_string() << '\n'
         << TypeInfo<const int *>().to_string() << '\n'
         << TypeInfo<long int *const>().to_string() << '\n';
    return 0;
}