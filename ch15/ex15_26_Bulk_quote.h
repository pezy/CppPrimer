/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 https://github.com/pezy/Cpp-Primer

Disc_quote class
 1. define copy-control members to do the same job as the synthesized versions.
 2. Print function name to trace the running.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_26_DISC_QUOTE_H
#define CP5_EX15_26_DISC_QUOTE_H

#include "ex15_26_Quote.h"

namespace EX26 {
class Bulk_quote : public Quote {
public:
    Bulk_quote() {
        cout << "Bulk_quote Constructor" << endl;
    }

    Bulk_quote(const string &b, double p, size_t q, double d) : Quote(b, p), min_qty(q), discount(d) {
        cout << "Bulk_quote Constructor taking four paramters" << endl;
    }

    Bulk_quote(const Bulk_quote& rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) {
        cout << "Bulk_quote Copy Constructor" << endl;
    }

    Bulk_quote& operator=(const Bulk_quote& rhs) {
        cout << "Bulk_quote Copy assignment operator" << endl;
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        return *this;
    }

    Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)),
                                            discount(std::move(rhs.discount)) {
        cout << "Bulk_quote Move constructor" << endl;
    }

    Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
        cout << "Bulk_quote Move assignment operator" << endl;
        Quote::operator=(rhs);
        min_qty = std::move(rhs.min_qty);
        discount = std::move(rhs.discount);
        return *this;
    }

    virtual ~Bulk_quote() {
        cout << "Bulk_quote destructor" << endl;
    }
    virtual double net_price(size_t cnt) const override {
        if (cnt >= min_qty) return cnt * (1 - discount) * price;
        else return cnt * price;
    }
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};
}

#endif //CP5_EX15_26_DISC_QUOTE_H
