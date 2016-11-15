//
//  ex7_15.h
//  Exercise 7.15
//
//  Created by zzzhhh on 11/15/16.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef CP5_ex7_15_h
#define CP5_ex7_15_h

#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::string;

//use “struct” default privileges is public
//use “calss” default privileges is private

class Person {
public:
	Person() = default;
	Person(const std::string sname, const string saddr)
		: name(sname), address(saddr),age(20)
	{
	}


	string getName() const { return name; }
	string getAddress() const { return address; }

private:
	string name;
	string address;
	int age;

};


int main()
{
	string name = "Ham";
	string adres = "china";
	Person obj(name, adres);
	string out = obj.getName();
	// Converting a string to a C-style string
	cout << out.c_str();
	return 0;
}

#endif
