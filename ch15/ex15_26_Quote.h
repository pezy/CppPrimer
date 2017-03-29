/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 https://github.com/pezy/Cpp-Primer

Quote class
 1. define copy-control members to do the same job as the synthesized versions.
 2. Print function name to trace the running.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_26_QUOTE_H
#define CP5_EX15_26_QUOTE_H

#include <string>
#include <iostream>

namespace EX26 {
    using std::string;
    using std::cout; using std::endl;

class Quote {
public:
    Quote() {
        cout << "Quote Constructor" << endl;
    }

    Quote(const string &b, double p) : bookNo(b), price(p) {
        cout << "Quote Constructor taking two parameters" << endl;
    }

    Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {
        cout << "Quote Copy Constructor" << endl;
    }

    Quote& operator=(const Quote &rhs) {
        cout << "Quote Copy assignment operator" << endl;
        price = rhs.price;
        bookNo = rhs.bookNo;
        return *this;
    }

    Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
        cout << "Quote Move Constructor" << endl;
    }

    Quote& operator=(Quote &&rhs) noexcept {
        cout << "Quote Move assignment operator" << endl;
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
        return *this;
    }

    virtual ~Quote() {
        cout << "Quote Destructor" << endl;
    }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
private:
    string bookNo;
protected:
    double price = 0.0;
};

}

#endif //CP_EX15_26_QUOTE_H
