#include <fstream>
#include <iostream>

#include "../ch07/ex7_26_sales_data.h"

int main(int argc, char** argv)
{
    std::ifstream input(argv[1]); // use "../data/book.txt"

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
    }
}

/*
 *! Output:
 *! 0-201-78345-X 5 110
 *! 0-201-78346-X 9 839.2
 */