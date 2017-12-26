// Using pointers, write a function to swap the values of two ints.
// Test the function by calling it and printing the swapped values.

#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void swap(int* const lhs, int* const rhs)
{
    auto tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

int main()
{
    for (int lht, rht; cout << "Please Enter:\n", cin >> lht >> rht;) {
        swap(&lht, &rht);
        cout << lht << " " << rht << endl;
    }
}
