// Write a function that takes an int and a pointer to an int and
// returns the larger of the int value or the value to which the
// pointer points. What type should you use for the pointer?

#include <iostream>

int LargerOne(int i, const int* const ip)
{
    return (i > *ip) ? i : *ip;
}

int main()
{
    int c = 6;
    std::cout << LargerOne(7, &c) << std::endl;
}
