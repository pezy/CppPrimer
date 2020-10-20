// prints the numbers from ten down to zero.(use while)

#include <iostream>

using namespace std;

int main()
{
    int val = 10;
    while (val >= 0) {
        cout << val << endl;
        --val; 
    }

    return 0;
}
