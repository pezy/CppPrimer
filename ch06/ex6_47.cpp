// Revise the program you wrote in the exercises in 6.3.2 (p.
// 228) that used recursion to print the contents of a vector to conditionally
// print information about its execution. For example, you might print the size
// of the vector on each call. Compile and run the program with debugging turned
// on and again with it turned off.

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

//#define NDEBUG

void printVec(vector<int>& vec)
{
#ifndef NDEBUG
    cout << "vector size: " << vec.size() << endl;
#endif
    if (!vec.empty()) {
        auto tmp = vec.back();
        vec.pop_back();
        printVec(vec);
        cout << tmp << " ";
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVec(vec);
    cout << endl;
}
