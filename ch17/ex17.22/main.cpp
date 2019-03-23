/***************************************************************************
*  @file       main.cpp
*  @author     Cheng668
*  @date       10  Sept 2016
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//!
//! Exercise 17.22
//! Rewrite your phone program so that it allows any number
//! of whitespace characters to separate the three parts of a phone number.

#include<iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include<fstream>
using std::ifstream;
using std::ofstream;

#include<sstream>
using std::istringstream;
using std::ostringstream;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::smatch;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const smatch& m);
void read_record(istream& is, ostream& ou, vector<PersonInfo>& people);
void format_record(ostream& os, const string& str, PersonInfo& people);
//! fake function that makes the program compile
string format(const string &num) { return num; }

int main()
{
	vector<PersonInfo> people;

	string filename;
	cout << "Please input a record file name: ";
	cin >> filename;
	cout << endl;
	ifstream fin(filename);
	
	if (fin.is_open())
	{
		ofstream fout("data\\result.txt", ofstream::trunc);
		read_record(fin, fout, people);
	}
	else
	{
		cout << "Fail to open file " << filename << endl;
	}
	system("pause");
	return 0;
}

bool valid(const smatch& m)
{
	//! if there is an open parenthesis before the area code
	if (m[1].matched)
		//! the area code must be followed by a close parenthesis
		//! and followed immediately by the rest of the number or a space
		return m[3].matched
		&& (m[4].matched == 0 || m[4].str() == " ");
	else
		//! then there can't be a close after the area code
		//! the delimiters between the other two components must match
		return !m[3].matched
		&& m[4].str() == m[6].str();
}

void read_record(istream& is,ostream& os, vector<PersonInfo>& people)
{
	string line, word; //! will hold a line and word from input, respectively
	//! read the input a line at a time until cin hits end-of-file (or another error)
	while (getline(is, line))
	{
		PersonInfo info; //! create an object to hold this record's data
		istringstream record(line); //! bind record to the line we just read
		record >> info.name; //! read the name
		while (getline(record, word)) //! read all the phone numbers includes the space character
			format_record(os,word,info);
		people.push_back(info); //! append this record to people
	}
	return;
}

void format_record(ostream& os, const string& phones, PersonInfo& people)
{
	string phone =
		"(\\()?(\\d{3})(\\))?([-.]|\\s*)?(\\d{3})([-.]|\\s*)?(\\d{4})\\b";
	regex r(phone);
	ostringstream formatted, badNums; //! objects created on each loop
	for (sregex_iterator it(phones.begin(), phones.end(), r), end_it;
	it != end_it; ++it)
	{
		//! check whether the number's formatting is valid
		if (!valid(*it))
			//! string in badNums
			badNums << " " << it->str();
		else
		{//! "writes" to formatted's string
			formatted << " " << format(it->str());
			people.phones.push_back(it->str());//!record the vaild phones 
		}
	}

	if (badNums.str().empty()) //! there were no bad numbers
		os << people.name << " " //! print the name
		<< formatted.str() << endl; //! and reformatted numbers
	else //! otherwise, print the name and bad numbers
		cerr << "input error: " << people.name
		<< " invalid number(s) " << badNums.str() << endl;
}
