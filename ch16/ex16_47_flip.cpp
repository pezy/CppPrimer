#include <iostream>

void f(int v1, int& v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int&& i, int& j)
{
	std::cout << i << " " << ++j << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
	int j = 0;
	flip(f, j, 42);
	flip(g, j, 42);
}