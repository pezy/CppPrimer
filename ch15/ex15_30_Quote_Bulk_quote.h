/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 https://github.com/pezy/Cpp-Primer

 Quote class and print_total function
 Bulk_quote class
 Both classes added clone member

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_30_QUOTE_H
#define CP5_EX15_30_QUOTE_H

#include <string>
#include <iostream>

inline namespace EX30 {

    using std::string;
    using std::ostream; using std::endl;
    using std::move;

class Quote {
public:
    Quote() = default;
    Quote(string const& b, double p) : bookNo(b), price(p) { }

    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote&&) = default;

    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(move(*this)); }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &b, double p, size_t q, double d) : Quote(b, p), min_qty(q), discount(d) {}

    Bulk_quote(const Bulk_quote& lhs) : Quote(lhs), min_qty(lhs.min_qty), discount(lhs.discount) {}
    Bulk_quote(Bulk_quote&& rhs) noexcept : Quote(move(rhs)), min_qty(move(rhs.min_qty)), discount(move(rhs.discount)) {}
    Bulk_quote& operator=(const Bulk_quote& lhs)
    { Quote::operator=(lhs); min_qty = lhs.min_qty; discount = lhs.discount; return *this; }
    Bulk_quote& operator=(Bulk_quote&& rhs) noexcept
    { Quote::operator=(move(rhs)); min_qty = move(rhs.min_qty), discount = move(rhs.discount); return *this; }

    virtual Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    virtual Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }

    virtual double net_price(std::size_t cnt) const override {
        if (cnt >= min_qty) return cnt * (1 - discount) * price;
        else return cnt * price;
    }
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(ostream& os, Quote const& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

}

#endif // CP5_EX15_30_QUOTE_H
