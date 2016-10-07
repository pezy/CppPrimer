/*
=================================================================================
C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

Write a function that interacts with the user, asking for a number and
generating the factorial of that number. Call this function from main.

About the magic number(13): https://github.com/Mooophy/Cpp-Primer/pull/172

If you have questions, try to connect with me: pezy<pezy.dev@gmail.com>
=================================================================================
*/

#include <iostream>
#include <string>

int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

void factorial_with_interacts() {
	for (int val = 0; std::cout << "Enter a number within [0, 13): ", std::cin >> val; ) {
		if (val < 0 || val > 12) continue;
		std::cout << val << "! =" << fact(val) << std::endl;
	}
}

int main()
{
	factorial_with_interacts();
}