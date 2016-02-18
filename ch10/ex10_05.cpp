//
//  ex10_05.cpp
//  Exercise 10.5
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  In the call to equal on rosters, what would happen if both rosters
//  held C-style strings, rather than library strings?
//  @Answer It's not quite the same as `std::string`
//  Maybe the function 'equal' return true when you make a comparison between 
//  two c-style strings containers. Nonetheless, we need to keep in mind that 
//  when it comes to comparison of c-style strings, we need to use 'strcmp' but 
//  not simply relational operators, for using relational operators is just 
//  comparison between the address of two c-style strings but not their values.


#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main()
{
    char c1[10] = "eipi10";
    char c2[10] = "eipi10";
    std::vector<char*> roster1{c1};
    std::list<char*> roster2{c2};
    std::cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    return 0;
}

// clang 3.5.0
// out
// 0
