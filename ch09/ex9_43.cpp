//
//  ex9_43.cpp
//  Exercise 9.43
//
//  Created by pezy on 12/4/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a function that takes three strings, s, oldVal, and newVal.
//          Using iterators, and the insert and erase functions replace
//          all instances of oldVal that appear in s by newVal.
//          Test your function by using it to replace common abbreviations,
//          such as "tho" by "though" and "thru" by "through".
//  @Compile    Gcc can't support return iterator of string::insert. Please use clang or VS2013

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void Replace(string &s, string const& oldVal, string const& newVal)
{
    auto val_size = oldVal.size();
    if (s.size() < val_size) return;

    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        if (string {iter, iter + val_size} == oldVal)
        {
//            iter = s.erase(iter, iter + val_size);
//            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            s.erase(iter, iter + val_size);
            s.insert(iter, newVal.cbegin(), newVal.cend()); // gcc 4.9 bug (see http://stackoverflow.com/questions/29690369)
            iter += newVal.size()-1;//do't forget "++iter", use "thruthru" can test this
        }
    }
}

int main()
{
    //two "thru" and two "tho"  to test
    string str {"To drive straight thruthru is a foolish, thotho courageous act."};
    str.reserve(2*str.size());//enough capacity to avoid allocating new memory while replacing
    Replace(str, "tho", "though");
    Replace(str, "thru", "through");
    cout << str << endl;
}

 
