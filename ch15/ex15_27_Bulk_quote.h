/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 https://github.com/pezy/Cpp-Primer

 Bulk_quote
 inherited constructors from EX15::Disc_quote

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_27_BULK_QUOTE_H
#define CP5_EX15_27_BULK_QUOTE_H

#include "ex15_15_Disc_quote.h"

inline namespace EX27 {

    using std::string;

class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    virtual double net_price(std::size_t cnt) const override {
        if (cnt >= quantity) return cnt * (1 - discount) * price;
        else return cnt * price;
    }
};

}

#endif // CP5_EX15_27_BULK_QUOTE_H
