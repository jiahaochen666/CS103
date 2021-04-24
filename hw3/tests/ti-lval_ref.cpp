#include "TypeInfo.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << TypeInfo<char &>().to_string() << '\n'
         << TypeInfo<short int &>().to_string() << '\n'
         << TypeInfo<int &>().to_string() << '\n'
         << TypeInfo<long int &>().to_string() << '\n';
    return 0;
}