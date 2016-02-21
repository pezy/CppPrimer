#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string pre_word, word, max_repeat_word;
    int repeat_times = 0, max_repeat_times = 0;
    
    while (cin >> word) {
        if (word == pre_word) {
            ++repeat_times;
        } else {
            repeat_times = 1;
            pre_word = word;
        }
        
        if (max_repeat_times < repeat_times) {
            max_repeat_times = repeat_times;
            max_repeat_word = pre_word;
        }
    }
    
    if (max_repeat_times <= 1){
        cout << "no word was repeated" << endl;
    } else {
        cout << "the word '" << max_repeat_word << "' occurred " << max_repeat_times << " times" << endl;
    }
}
