#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;


template <typename T>
size_t count(const vector<T> & v, T val)
{
    size_t c = 0;
    for (auto & elem : v)
    {
        if (elem == val)
            ++c;
    }
    return c;
}


int main()
{
    vector<double> dv = {1, 2, 3, 4, 1, 3, 1, 2, 3, 4, 2, 4};
    vector<int> iv = {2, 2, 1, 4, 2, 1, 4, 5, 6, 4, 3, 4};
    vector<string> sv = {"hello", "bye", "good", "hello", "fun", "hello"};

    cout << "{1, 2, 3, 4, 1, 3, 1, 2, 3, 4, 2, 4} has: ";
    cout << count(dv, 1.0) <<  " 1" << endl;

    cout << "{2, 2, 1, 4, 2, 1, 4, 5, 6, 4, 3, 4} has: ";
    cout << count(iv, 2) <<  " 2" << endl;

    cout << "{\"hello\", \"bye\", \"good\", \"hello\", \"fun\", \"hello\"} has: ";
    cout << count(sv, string("hello")) <<  " hello" << endl;
    
}

