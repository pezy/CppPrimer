#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::endl;
using std::string;

template <typename T>
ostream & print(ostream & os, const T & t)
{
    return os << t << endl;
}

template <typename T, typename ... Args>
ostream & print(ostream & os, const T & t, const Args& ... rest)
{
    os << t << ", ";
    return print(os, rest...);

}


int main()
{
    int i = 2;
    double d = 1.23123;
    char c = 'c';
    string s = "this is a string";
    cout << "print(cout, i) : " << endl;
    print(cout, i);
    cout << "print(cout, d, s) : " << endl;
    print(cout, d, s);
    cout << "print(cout, i, d, s, c, \"this is a C string\") : " << endl;
    print(cout, i, d, s, c, "this is a C string");
}
