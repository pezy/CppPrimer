#include <iostream>
#include <typeinfo>

int main() {
  const int i = 42;
  auto j = i;
  const auto &k = i;
  auto *p = &i;
  const auto j2 = i, &k2 = i;

  std::cout << "i  is " << typeid(i).name() << "\n";
  std::cout << "j  is " << typeid(j).name() << "\n";
  std::cout << "k  is " << typeid(k).name() << "\n";
  std::cout << "p  is " << typeid(p).name() << "\n";
  std::cout << "j2 is " << typeid(j2).name() << "\n";
  std::cout << "k2 is " << typeid(k2).name() << "\n";

  std::cout << std::endl;
  std::cout << std::boolalpha;

  std::cout << "i and j  have same type? "
            << std::is_same<decltype(i), decltype(j)>::value << "\n";
  std::cout << "i and k  have same type? "
            << std::is_same<decltype(i), decltype(k)>::value << "\n";
  std::cout << "i and j2 have same type? "
            << std::is_same<decltype(i), decltype(j2)>::value << "\n";
  std::cout << "j and j2 have same type? "
            << std::is_same<decltype(j), decltype(j2)>::value << "\n";
  std::cout << "k and k2 have same type? "
            << std::is_same<decltype(k), decltype(k2)>::value << "\n";

  return 0;
}
