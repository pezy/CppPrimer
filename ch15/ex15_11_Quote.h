/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/Cpp-Primer

Quote class and print_total function
added debug() function

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_11_QUOTE_H_
#define CP5_EX15_11_QUOTE_H_

#include <string>
#include <iostream>

inline namespace EX11 {

    using std::string;
    using std::ostream; using std::endl; using std::cout;

class Quote {
public:
    Quote() = default;
    Quote(string const& b, double p) : bookNo(b), price(p) { }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const { cout << "data members: \n" << "\tbookNo: " << bookNo << "\tprice: " << price << endl; }

    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total(ostream& os, Quote const& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

}

#endif // CP5_EX15_11_QUOTE_H_
