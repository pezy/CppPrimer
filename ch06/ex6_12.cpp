// Rewrite the program from exercise 6.10 in 6.2.1 (p. 210) to use
// references instead of pointers to swap the value of two ints. Which
// version do you think would be easier to use and why?
// The version using reference is easier.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void swap(int& lhs, int& rhs)
{
    auto tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main()
{
    for (int left, right; cout << "Please Enter:\n", cin >> left >> right;) {
        swap(left, right);
        cout << left << " " << right << endl;
    }
}
