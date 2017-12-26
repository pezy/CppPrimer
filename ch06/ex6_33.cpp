// Write a recursive function to print the contents of a vector

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using Iter = vector<int>::iterator;

void print(Iter beg, Iter end)
{
    if (beg != end) {
        cout << *beg << " ";
        print(std::next(beg), end);
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec.begin(), vec.end());
}
