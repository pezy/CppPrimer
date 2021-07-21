//
//  ex13_31.h
//  Exercise 13.31
//
//  Created by pezy on 1/23/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Give your class a < operator and define a vector of HasPtrs.
//  Give that vector some elements and then sort the vector.
//  Note when swap is called.
//
//  See ex13_30.h

#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h

#include <string>
#include <iostream>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(HasPtr tmp)
    {
        this->swap(tmp);
        return *this;
    }
    ~HasPtr() { delete ps; }

    void swap(HasPtr& rhs)
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }

    void show() const { std::cout << *ps << std::endl; }
private:
    std::string* ps;
    int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    lhs.swap(rhs);
}
//Function swap(HasPtr&, HasPtr&) is actually never used. The notice is printed because '=' is called, and 'sort' doesn't call swap(HasPtr&, HasPtr&) at all. 
//I saw a comment that might be the reason:
//swap(HasPtr&, HasPtr&) is used in quicksort, but 'sort' won't use quicksort when there are not enough elements in the container(insertionsort is used instead).

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}

#endif
