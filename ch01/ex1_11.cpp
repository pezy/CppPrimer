#include <iostream>

int main() {
    int small = 0, big = 0;
    std::cout << "Please input two integers:";
    std::cin >> small >> big;

    while (small > big) {
        int temp = small;
        small = big;
        big = temp;
    }
    // The numbers are now switch to proper big and small if necessary



    while (small <= big) {
        std::cout << small << std::endl;
        small++;
    }

    // code for if you wanted to print with for loop:
    /*
    //for (int i = small; i < big+1; i++) {
    //    std::cout << i << std::endl;
    //}*/
    return 0;
}