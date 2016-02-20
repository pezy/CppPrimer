#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string str1;
    string tempstr, laststr;
    int count = 0, tempCount = 0;      // 计数 count
    
    while (cin >> tempstr)
    {
        if (tempCount == 0)
            laststr = tempstr;
        if (tempstr == laststr)
            ++tempCount;
        else
        {
            laststr = tempstr;
            tempCount = 1;              // 次数置为1
        }
        if (tempCount > count)
        {
            count = tempCount;
            str1 = tempstr;
        }
    }
    
    if (count == 1)
        cout << "All words are single!" << endl;
    else
        cout << "\"" << str1 << "\" appears " << count << " times" << endl;
    
    return 0;
}
