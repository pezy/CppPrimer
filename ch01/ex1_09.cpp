// sum the numbers from 50 to 100 (use while)

#include <iostream>

using namespace std; 

//“using namespace std” means we use the namespace named std. “std” is an abbreviation for standard. 
//If we don’t want to use this line of code, we can use the things in this namespace like this. std::cout, std::endl.
//If this namespace is not used, then computer finds for the cout, cin and endl etc.. Computer cannot identify those and therefore it throws errors.


int main()
{
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val; //shorthand for sum=sum+val
        ++val; //increments the value of val by 1.
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}

// output: The sum is: 3825
