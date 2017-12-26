// Write a function to swap two int pointers.

#include <iostream>

void swap(const int*& lhs, const int*& rhs)
{
    auto temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main()
{
    const int i = 42, j = 99;
    auto lhs = &i;
    auto rhs = &j;
    swap(lhs, rhs);
    std::cout << *lhs << " " << *rhs << std::endl;
}
