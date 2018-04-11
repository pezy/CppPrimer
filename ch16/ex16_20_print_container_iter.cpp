#include <iostream>
#include <vector>

template <typename Container>
std::ostream& print(const Container& c, std::ostream& os = std::cout)
{
    for (auto iter = c.begin(); iter != c.end(); ++iter) {
        os << *iter << " ";
    }
    return os;
}

int main()
{
    std::vector<int> vec{2, 4, 6, 8, 7, 5, 3, 1};
    print(vec) << "\n";
}