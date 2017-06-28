#include <cassert>
#include <fstream>

#include "ex17_04_findBook.h"
#include "ex17_05_findBook.h"
#include "ex17_06_findBook.h"

vector<Sales_data> build_store(const string& s)
{
    vector<Sales_data> ret;
    std::ifstream is(s);
    Sales_data item;
    while (is >> item) ret.push_back(item);
    sort(ret.begin(), ret.end(),
         [](const Sales_data& lhs, const Sales_data& rhs) {
             return lhs.isbn() < rhs.isbn();
         }); //! need sort for equal_range to work
    return ret;
}

int main()
{
    // each element in files holds the transactions for a particular store
    vector<vector<Sales_data>> files;
    for (int cnt = 1; cnt <= 4; ++cnt)
        files.push_back(build_store("../data/store" + std::to_string(cnt)));

    EX04::reportResults(std::cin, std::cout, files);
    // EX05::reportResults(std::cin, std::cout, files);
    // EX06::reportResults(std::cin, std::cout, files);
}

//! Compile
// cc ex17_findBook_test.cpp ../ch14/ex14_45_sales_data.cpp -std=c++11 -pedantic
// -Wall
//
//! Run
// Enter the book ISBN to look for: 0-201-70353-X
// store 1 sales: 0-201-70353-X 4 99.96 24.99
// store 3 sales: 0-201-70353-X 4 99.96 24.99
// store 4 sales: 0-201-70353-X 4 99.96 24.99
// ----
// Enter the book ISBN to look for: 0-201-88954-4
// store 1 sales: 0-201-88954-4 16 198 12.375
// store 3 sales: 0-201-88954-4 16 198 12.375
// store 4 sales: 0-201-88954-4 16 198 12.375
// ----
// Enter the book ISBN to look for: 0-201-78345-X
// store 1 sales: 0-201-78345-X 5 110 22
// store 2 sales: 0-201-78345-X 14 320 22.8571
// store 3 sales: 0-201-78345-X 5 110 22
// store 4 sales: 0-201-78345-X 5 110 22
// ----
// Enter the book ISBN to look for: