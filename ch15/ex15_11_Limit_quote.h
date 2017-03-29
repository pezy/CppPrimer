/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/Cpp-Primer

Limit_quote class
added debug function

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_11_LIMIT_QUOTE_H_
#define CP5_EX15_11_LIMIT_QUOTE_H_

#include "ex15_11_Bulk_quote.h"
#include <string>

namespace EX11 {
    using std::string;
    using std::cout; using std::endl;

class Limit_quote : public Bulk_quote {
public:
    Limit_quote() = default;
    Limit_quote(string const& book, double p, size_t min, size_t max, double dist) : Bulk_quote(book, p, min, dist), max_qty(max) {}

    double net_price(size_t cnt) const final override {
        if (cnt > max_qty) return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
        else if (cnt >= min_qty) return cnt * (1 - discount) * price;
        else return cnt * price;
    }

    virtual void debug() const final {
        Bulk_quote::debug();
        cout << "\tmax_qty: " << max_qty << endl;
    }

private:
    size_t max_qty = 0;
};
}

#endif // CP5_EX15_11_LIMIT_QUOTE_H_
