#include "ch15.h"
using namespace ch15;

int main()
{
    EX03::Quote quote_03("0-201-78345-X", 23.8);
    EX03::print_total(std::cout, quote_03, 3);

    EX05::Bulk_quote bulk_quote("0-201-78345-X", 23.8, 3, 0.5);
    EX03::print_total(std::cout, bulk_quote, 4);

    EX07::Limit_quote limit_quote("0-201-78345-X", 23.8, 3, 5, 0.5);
    EX03::print_total(std::cout, limit_quote, 6);
}
