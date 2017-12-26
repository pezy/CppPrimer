// Write your own versions of each of the print functions
// presented in this section. Call each of these functions to print i and j
// defined as follows:
// int i = 0, j[2] = {0, 1};

#include <iostream>

using std::begin;
using std::cout;
using std::end;
using std::endl;

void print(int* const pi)
{
    if (pi) cout << *pi << endl;
}

void print(const char* p)
{
    if (p)
        while (*p) cout << *p++;
    cout << endl;
}

void print(const int* beg, const int* end)
{
    while (beg != end) cout << *beg++ << " ";
    cout << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) cout << ia[i] << " ";
    cout << endl;
}

void print(const int (&arr)[2])
{
    for (auto i : arr) cout << i << " ";
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    char ch[5] = "pezy";

    print(ch);
    print(begin(j), end(j));
    print(&i);
    print(j, end(j) - begin(j));
    print(const_cast<const int(&)[2]>(j));
}
