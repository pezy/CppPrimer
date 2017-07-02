#include <exception>
#include <iostream>
#include <regex>
#include <string>

using std::regex;

//! @check https://en.wikipedia.org/wiki/I_before_E_except_after_C
int main()
{
    try {
        regex r("[[:alpha:]]*(cie|[^c]ei)[[:alpha:]]*");
        std::string word;
        while (std::cout << "Enter a word, or q to quit: ", std::cin >> word) {
            if (word == "q") break;
            std::smatch result;
            if (std::regex_search(word, result, r))
                std::cout << "Violate the rule: 'i before e except after c'"
                          << std::endl;
            else
                std::cout << word + " is okay." << std::endl;
        }
    }
    catch (std::regex_error e) {
        std::cout << e.what() << "\ncode:" << e.code() << std::endl;
    }
}

//! @test
// Enter a word, or q to quit: believe
// believe is okay.
// Enter a word, or q to quit: receive
// receive is okay.
// Enter a word, or q to quit: species
// Violate the rule: 'i before e except after c'
// Enter a word, or q to quit: seize
// Violate the rule: 'i before e except after c'
// Enter a word, or q to quit: q