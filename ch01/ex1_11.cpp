// Print each number in the range specified by two integers.

#include <iostream>

int main()
{
    std::cout << "Please enter two integers:" << std::endl;

    int a = 0;
    int b = 0;
    int small = 0;
    int large = 0;
    std::cin >> a >> b;
    
    large = a;
    small = b;
    
    while (b > large) {
        small = a;
        large = b;
    }
    
    while (small <= large) {
        std::cout << small << "  ";
        ++small;
    }
    std::cout << std::endl;

    return 0;
}
