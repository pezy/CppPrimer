#include <algorithm>
#include <numeric>
#include <vector>

#include "../ch07/ex7_26_sales_data.h" // Sales_data class.

bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2)
{
    return sd1.isbn() < sd2.isbn();
}

int main()
{
    Sales_data d1("CppPrimer"), d2("JavaCore"), d3("PythonCookBook"),
        d4("CppCore"), d5("AwesomeCPP");
    std::vector<Sales_data> v{d1, d2, d3, d4, d5};

    //! @note   the elements the iterators pointing to
    //!         must match the parameters of the predicate.
    std::sort(v.begin(), v.end(), compareIsbn);

    for (const auto& element : v) std::cout << element.isbn() << " ";
    std::cout << std::endl;
}
