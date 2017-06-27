#include "ex17_03_text_query.h"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace EX03 {

using std::get;

TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
    string txt;
    while (getline(is, txt)) {    // for each line in the file
        file->push_back(txt);     // remember this line of text
        int n = file->size() - 1; // the current line number
        // remove punctuation from the statement
        txt.erase(std::remove_if(txt.begin(), txt.end(), ::ispunct), txt.end());
        std::istringstream line(txt); // separate the line into words
        string word;
        while (line >> word) { // for each word in that line.
            // if word isn't already in wm, subscripting adds a new entry
            auto& lines = wm[word]; // lines is a shared_ptr
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>); // allocate the new
            lines->insert(n);                  // insert this line number
        }
    }
}

query_result TextQuery::query(const string& sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end()) return std::make_tuple(sought, nodata, file);
    return std::make_tuple(sought, loc->second, file);
}

string make_plural(size_t ctr, string const& word, string const& ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream& print(ostream& os, const query_result& qr)
{
    // if the word was found, print the count and all occurrences.
    os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " "
       << make_plural(get<1>(qr)->size(), "time", "s") << std::endl;
    // print each line in which the word appeared
    for (auto num : *get<1>(qr)) // for every element in the set
        // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") " << *(get<2>(qr)->begin() + num)
           << std::endl;
    return os;
}
}