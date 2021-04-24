#include "TypeInfo.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << TypeInfo<volatile char>().to_string() << '\n'
         << TypeInfo<volatile short int>().to_string() << '\n'
         << TypeInfo<volatile int>().to_string() << '\n'
         << TypeInfo<volatile long int>().to_string() << '\n';
    return 0;
}