//! @file   Exercise 9.15
//! @author pezy
//! @date   2014-12-02
//! @Brief  Write a program to determine whether two vector<int>s are equal.

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{1, 2, 3, 4, 5};
    std::vector<int> vec3{1, 2, 3, 4};

    std::cout << std::boolalpha << (vec1 == vec2) << std::endl;
    std::cout << std::boolalpha << (vec1 == vec3) << std::endl;

    return 0;
}
