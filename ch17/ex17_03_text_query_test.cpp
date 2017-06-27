#include "ex17_03_text_query.h"

void runQueries(ifstream& infile)
{
    EX03::TextQuery tq(infile);
    while (true) {
        std::cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        EX03::print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    ifstream file("../data/storyDataFile.txt");
    runQueries(file);
}