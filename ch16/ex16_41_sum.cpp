#include <climits>
#include <iostream>

template <typename T> struct promote;

template <> struct promote<short int> {
    using type = int;
};

template <> struct promote<unsigned short int> {
    using type = unsigned int;
};

template <> struct promote<int> {
    using type = long long int;
};

template <> struct promote<unsigned int> {
    using type = unsigned long int;
};

template <> struct promote<long int> {
    using type = long long int;
};

template <> struct promote<unsigned long int> {
    using type = unsigned long int;
};

template <> struct promote<long long int> {
    using type = unsigned long long int;
};

template <> struct promote<unsigned long long int> {
    using type = unsigned long long int;
};

template <> struct promote<float> {
    using type = double;
};

template <> struct promote<double> {
    using type = long double;
};

template <> struct promote<long double> {
    using type = long double;
};

template <typename T> using promote_t = typename promote<T>::type;

template <typename T> auto sum(T lhs, T rhs) -> promote_t<T>
{
    return static_cast<promote_t<T>>(lhs) + rhs;
}

int main()
{
    std::cout << sum(std::numeric_limits<short int>::max(),
                     std::numeric_limits<short int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<unsigned short int>::max(),
                     std::numeric_limits<unsigned short int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<int>::max(),
                     std::numeric_limits<int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<unsigned int>::max(),
                     std::numeric_limits<unsigned int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<long int>::max(),
                     std::numeric_limits<long int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<unsigned long int>::max(),
                     std::numeric_limits<unsigned long int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<long long int>::max(),
                     std::numeric_limits<long long int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<unsigned long long int>::max(),
                     std::numeric_limits<unsigned long long int>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<float>::max(),
                     std::numeric_limits<float>::max())
              << std::endl;
    std::cout << sum(std::numeric_limits<double>::max(),
                     std::numeric_limits<double>::max())
              << std::endl; // too large
    std::cout << sum(std::numeric_limits<long double>::max(),
                     std::numeric_limits<long double>::max())
              << std::endl; // too large
}
