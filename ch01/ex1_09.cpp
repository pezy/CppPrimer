#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0, val ;
    cout<<"Enter the value \n";
    while (val <= 100) {
        sum += val;
        ++val;
    }
    cout<<"the sum is: "<<sum<<endl;
    return 0;
}
