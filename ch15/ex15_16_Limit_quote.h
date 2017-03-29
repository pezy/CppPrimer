/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/Cpp-Primer

Limit_quote class
inherit from Disc_quote

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_16_LIMIT_QUOTE_H_
#define CP5_EX15_16_LIMIT_QUOTE_H_

#include "ex15_15_Disc_quote.h"
#include <string>

namespace EX16 {
    using std::string;
    using std::cout; using std::endl;
    using namespace EX15;

class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(string const& book, double p, size_t min, size_t max, double dist) : Disc_quote(book, p, min, dist), max_qty(max) {}

    double net_price(size_t cnt) const final override {
        if (cnt > max_qty) return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
        else if (cnt >= quantity) return cnt * (1 - discount) * price;
        else return cnt * price;
    }

private:
    size_t max_qty = 0;
};
}

#endif // CP5_EX15_16_LIMIT_QUOTE_H_
