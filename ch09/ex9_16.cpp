//! @file   Exercise 9.16
//! @author pezy
//! @date   2014-12-02
//! @Brief  Repeat the previous program, but compare elements in a list<int> to
//! a vector<int>.

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> list{1, 2, 3, 4, 5};
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{1, 2, 3, 4};

    std::cout << std::boolalpha
              << (std::vector<int>(list.begin(), list.end()) == vec1)
              << std::endl;
    std::cout << std::boolalpha
              << (std::vector<int>(list.begin(), list.end()) == vec2)
              << std::endl;
}
