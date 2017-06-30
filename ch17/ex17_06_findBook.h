#pragma once

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#include "../ch14/ex14_45_sales_data.h"

using std::pair;
using std::vector;
using std::string;
using std::make_pair;

namespace EX06 {
struct Matches {
    friend class Sales_data;

    Matches(vector<Sales_data>::size_type i,
            vector<Sales_data>::const_iterator b,
            vector<Sales_data>::const_iterator e)
        : index(i), begin(b), end(e)
    {
    }

    vector<Sales_data>::size_type index;
    vector<Sales_data>::const_iterator begin;
    vector<Sales_data>::const_iterator end;
};

vector<Matches> findBook(const vector<vector<Sales_data>>& files,
                         const string& book)
{
    vector<Matches> ret; // initally empty
    // for each store find the range of matching books, if any
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        // find the range of Sales_data that have the same ISBN
        auto found =
            std::equal_range(it->cbegin(), it->cend(), Sales_data(book),
                             [](const Sales_data& sd1, const Sales_data& sd2) {
                                 return sd1.isbn() < sd2.isbn();
                             });
        if (found.first != found.second) // this store had sales
            // remember the index of this store and the matching range
            ret.push_back(
                Matches(it - files.cbegin(), found.first, found.second));
    }
    return ret; // empty if no matches found
}

void reportResults(std::istream& in, std::ostream& os,
                   const vector<vector<Sales_data>>& files)
{
    string s;
    while (std::cout << "Enter the book ISBN to look for: ", in >> s) {
        auto trans = findBook(files, s); // stores that sold this book
        if (trans.empty()) {
            std::cout << s << " not found in any stores." << std::endl;
            continue; // get the next book to look for
        }
        for (auto&& store : trans) { // // for every store with a sale
            // get<n> returns the specified member from the tuple in store
            os << "store " << store.index + 1 << " sales: "
               << std::accumulate(store.begin, store.end, Sales_data(s))
               << std::endl;
        }
        std::cout << "----" << std::endl;
    }
}
} // namespace EX06