// reads a string of characters including punctuation and writes what was read
// but with the punctuation removed.

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s;
    string output_string;
    cout << "Enter a string of characters including punctuation." << endl;
    while (getline(cin, s)) {
        for (auto i : s)
            if (!ispunct(i)) 
                output_string+=c;
                
        cout <<output_string<< endl;
    }

    return 0;
}
