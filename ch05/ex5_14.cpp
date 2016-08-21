#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
    //subsection 5.4.1 is about 'while',so it's appropriate to use 'while'
void max_duplicate_while(){
    pair<string,int> max_duplicated;
    int count = 0;
    string str, prestr;
    while(cin >> str){
        if(str == prestr) ++count;
        else count = 0;
        if (count > max_duplicated.second) max_duplicated = {prestr, count};
        prestr = str;
    }
    if (max_duplicated.first.empty()) cout << "There's no duplicated string." << endl;
    else cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;
}

void max_duplicate_for(){
    pair<string, int> max_duplicated;
    int count = 0;
    for (string str, prestr; cin >> str; prestr = str)
    {
        if (str == prestr) ++count;
        else count = 0;
        if (count > max_duplicated.second) max_duplicated = { prestr, count };
    }
    
    if (max_duplicated.first.empty()) cout << "There's no duplicated string." << endl;
    else cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;
}

int main()
{
    max_duplicate_while();
    //max_duplicate_for();
    return 0;
}
