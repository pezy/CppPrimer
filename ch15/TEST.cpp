#include "ch15.h"
using namespace ch15;

int main()
{
    cout << "\n===== ex03 =====" << endl;

    EX03::Quote quote_03("0-201-78345-X", 23.8);
    EX03::print_total(std::cout, quote_03, 3);

    cout << "\n===== ex05 =====" << endl;

    EX05::Bulk_quote bulk_quote("0-201-78345-X", 23.8, 3, 0.5);
    EX03::print_total(std::cout, bulk_quote, 4);

    cout << "\n===== ex07 =====" << endl;

    EX07::Limit_quote limit_quote("0-201-78345-X", 23.8, 3, 5, 0.5);
    EX03::print_total(std::cout, limit_quote, 6);

    cout << "\n===== ex11 =====" << endl;

    EX11::Quote quote_11("0-201-82470-1", 50);
    EX11::Bulk_quote bulk_quote_11("0-201-82470-1", 50, 5, .19);
    EX11::Limit_quote limit_quote_11("0-201-82470-1", 50, 5, 10, .19);

    quote_11.debug();
    bulk_quote_11.debug();
    limit_quote_11.debug();

    cout << "\n===== ex15 =====" << endl;

    EX15::Bulk_quote bulk_quote_15("0-201-82470-1", 50, 5, .19);
    EX03::print_total(std::cout, bulk_quote_15, 6);
}
