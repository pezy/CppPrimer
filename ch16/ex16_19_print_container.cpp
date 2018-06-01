#include <iostream>
#include <vector>

template <typename Container>
std::ostream& print(const Container& c, std::ostream& os = std::cout)
{
    using size_type = typename Container::size_type;
    for (size_type i = 0; i != c.size(); ++i) {
        os << c.at(i) << " ";
    }
    return os;
}

int main()
{
    std::vector<int> vec{2, 4, 6, 8, 7, 5, 3, 1};
    print(vec) << "\n";
}