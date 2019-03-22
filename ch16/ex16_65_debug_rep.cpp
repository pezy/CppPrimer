#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;    
using std::cout;
using std::endl;

    
template <typename T>
string debug_rep(T t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <>
string debug_rep(const char * t)
{
   return t; 
}

template <>
string debug_rep(char * t)
{
   return t; 
}


int main()
{
    string s = "this is a string";
    cout << debug_rep("this is a literal string") << endl;
    cout << debug_rep(s) << endl;
    cout << debug_rep('c') << endl;
}
