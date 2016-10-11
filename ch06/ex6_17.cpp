#include <iostream>
#include <string>

using std::string;

bool hasUppercase(const string& str)
{
    for (auto c : str)
        if (isupper(c)) return true;
    return false;
}

const string& makeLowercase(string& str)
{
    for (auto& c : str)
        if (isupper(c)) c = tolower(c);
    return str;
}

int main()
{
    string str("Hello World!");
    std::cout << std::boolalpha << hasUppercase(str) << std::endl;
    std::cout << makeLowercase(str) << std::endl;
}
