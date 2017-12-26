// Write a main function that takes two arguments.
// Concatenate the supplied arguments and print the resulting string.

// Write a program that accepts the options presented
// in this section. Print the values of the arguments passed to main.

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string str;
    for (int i = 1; i != argc; ++i) {
        str += argv[i];
        str += " ";
    }

    std::cout << str << std::endl;
}
