#include <exception>
#include <iostream>
#include <regex>
#include <string>

using std::regex;

int main()
{
    try {
        regex r("[[:alnum]+\\.(cpp|cxx|cc)$", regex::icase);
    }
    catch (std::regex_error e) {
        std::cout << e.what() << "\ncode:" << e.code() << std::endl;
    }
}

// output
// Unexpected end of character class.
// code:1