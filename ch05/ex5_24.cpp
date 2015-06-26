#include <iostream>
#include <stdexcept>

int main(void)
{
    int a, b;
    std::cin >> a >> b;

    if (b == 0) throw std::runtime_error("divisor is 0");

    std::cout << static_cast<double>(a) / b << std::endl;

    return 0;
}
