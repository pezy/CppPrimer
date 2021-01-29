// Write a main function that takes two arguments.
// Concatenate the supplied arguments and print the resulting string.

// Write a program that accepts the options presented
// in this section. Print the values of the arguments passed to main.

#include <iostream>
#include <string>

int main(int argc, char* argv)
{
    std::cout << "enter the no of times string to be concatenated :";
    std::cin >> argc;
    std::cout << "enter the string to be concatenated";
    std::cin >> argv;

    std::string str = argv;
    
    for (int i = 1; i < argc; i++) {
         str  += argv;  //str =str + argv;
    }
    std::cout << "Concatenated string is : " << str;
}
