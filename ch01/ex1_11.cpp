// Print each number in the range specified by two integers.

#include <iostream>

int main()
{
    std::cout << "Please enter an integer: ";
    int number1 = 0;
    std::cin >> number1;

    std::cout << "Please enter one more integer: ";
    int number2 = 0;
    std::cin >> number2;

    while(number1 < number2){
        std::cout << number1 << std::endl;
        ++number1;
    }
    while(number1 >= number2){
        std::cout << number1 << std::endl;
        --number1;
    }
    return 0;
}
