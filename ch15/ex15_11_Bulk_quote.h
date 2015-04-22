/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/Cpp-Primer

Bulk_quote class
added debug() function

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_11_BULK_QUOTE_H_
#define CP5_EX15_11_BULK_QUOTE_H_

#include "ex15_11_Quote.h"
#include <string>

namespace EX11 {
    using std::string;

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(string const& book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

    virtual double net_price(size_t cnt) const override {
        if (cnt >= min_qty) return cnt * (1 - discount) * price;
        else return cnt * price;
    }

    virtual void debug() const override {
        Quote::debug();
        cout << "\tminqty: " << min_qty << "\tdiscount: " << discount << endl;
    }

protected:
    size_t min_qty = 0;
    double discount = 0.0;
};
}

#endif // CP5_EX15_11_BULK_QUOTE_H_
