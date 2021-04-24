#include "Format.hpp"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        cout << safe_format("Hello %s!\n");
    }
    catch (format_error &e)
    {
        cout << e.what() << "\n";
    }
    return 0;
}