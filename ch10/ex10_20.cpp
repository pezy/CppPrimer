/*!
 *  @question:
 *    The library defines an algorithm named `count_if`.
 *    Like `find_if`, this function takes a pair of iterators
 *    denoting an input range and a predicate that
 *    it applies to each element in the given range.
 *    `count_if` returns a count of how often the predicate is true.
 *    Use `count_if` to rewrite the portion of our program that
 *    counted how many words are greater than length 6.
 *  @author: pezy
 *  @date:  2016-07-01
 *  @see:   [Implicit Captures] - biggies funciton.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<string> words{"cppprimer", "pezy",    "learncpp",
                         "greater",   "rewrite", "programmer"};

    cout << std::count_if(words.cbegin(), words.cend(), [](const string& word) {
        return word.size() > 6;
    }) << std::endl;
}
