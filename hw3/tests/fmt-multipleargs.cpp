#include "Format.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << safe_format("%s%c%d %s!\n", "Hello", ' ', 1, "world");
    return 0;
}