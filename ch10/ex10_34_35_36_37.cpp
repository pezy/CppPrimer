//! @Alan @pezy
//!
//! Exercise 10.34:
//! Use reverse_iterators to print a vector in reverse order.
//!
//! Exercise 10.35:
//! Now print the elements in reverse order using ordinary iterators.
//!
//! Exercise 10.36:
//! Use find to find the last element in a list of ints with value 0.
//!
//! Exercise 10.37:
//! Given a vector that has ten elements, copy the elements from positions
//! 3 through 7 in reverse order to a list.
//!

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
    std::vector<int> v = {4, 5, 7, 9, 6, 3, 1, 0, 2, 3};

    //! 10.34
    for (auto iter = v.crbegin(); iter != v.crend(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    //! 10.35
    for (auto iter = v.cend(); iter != v.cbegin();)
        std::cout << *--iter << " ";
    std::cout << std::endl;

    //! 10.36
    std::list<int> l = {3, 7, 0, 3, 4, 0, 5};
    auto found = std::find(l.crbegin(), l.crend(), 0);
    std::cout << *found << " in front of " << *found.base() << std::endl;

    //! 10.37
    std::list<int> ret_l(7 - 3 + 1);
    std::reverse_copy(v.cbegin() + 3, v.cbegin() + 8, ret_l.begin());
    for (auto i : ret_l)
        std::cout << i << " ";
    std::cout << std::endl;
}
