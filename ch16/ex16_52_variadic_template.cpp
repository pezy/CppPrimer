#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

template <typename T, typename ... Args>
void foo(const T & t, const Args& ... rest)
{
    cout << "sizeof...(Args): " << sizeof...(Args) << endl;
    cout << "sizeof...(rest): " << sizeof...(rest) << endl;
}

int main()
{
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";
    cout << "foo(i, s, 42, d) : " << endl;
    foo(i, s, 42, d);
    cout << "foo(s, 42, \"hi\") : " << endl;
    foo(s, 42, "hi");
    cout << "foo(d, s) : " << endl;
    foo(d, s);
    cout << "foo(\"hi\") : " << endl;
    foo("hi"); 
}
