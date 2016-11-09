//
//  ex12_23.cpp
//  Exercise 12.23
//
//  Created by pezy on 12/30/14.
//  Updated by sanerror on 11/9/16.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program to concatenate two string literals, putting the result in a
//  dynamically allocated array of char.
//  Write a program to concatenate two library strings that have the same value
//  as the literals used in the first program.

#include <iostream>
#include <string>
#include <cstring>

int main() {
	const char *c1 = "Hello ";
	const char *c2 = "World";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	strcat_s(r, len, c1);
	strcat_s(r, len, c2);
	std::cout << r << std::endl;

	std::string s1 = "Hello ";
	std::string s2 = "World";
	strcpy_s(r, len, (s1 + s2).c_str());
	std::cout << r << std::endl;

	delete[] r;

	return 0;
}
