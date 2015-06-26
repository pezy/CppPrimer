#include <iostream>

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    std::cout << static_cast<double>(a) / b << std::endl;

    return 0;
}
