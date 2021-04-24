#include "Format.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << safe_format("Hello %s!\n", "world");
    return 0;
}