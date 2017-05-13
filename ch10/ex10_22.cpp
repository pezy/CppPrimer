//
//  ex10_22.cpp
//  Exercise 10.22
//
//  Created by pezy on 12/11/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the program to count words of size 6 or less using
//          functions in place of the lambdas.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>


using std::string;
using namespace std::placeholders;

bool lessThanOrEqualTo(const string& s, string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    std::vector<string> authors{"Mooophy", "pezy", "Queequeg90", "shbling",
                                "evan617"};
    std::cout << count_if(authors.cbegin(), authors.cend(),
                          bind(lessThanOrEqualTo, _1, 6));
}

//  @Out
//  1