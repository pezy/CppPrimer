#include "ch15.h"
using namespace ch15;

int main()
{
    EX03::Quote quote_03("0-201-78345-X", 23.8);
    EX03::print_total(std::cout, quote_03, 3);
}
