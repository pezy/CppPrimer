//
//  ex9_52.cpp
//  Exercise 9.52 
//
//  Created by pezy on 12/5/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Use a stack to process parenthesized expressions. 
//          When you see an open parenthesis, note that it was seen. 
//          When you see a close parenthesis after an open parenthesis, 
//          pop elements down to and including the open parenthesis off the stack. 
//          push a value onto the stack to indicate that a parenthesized expression was replaced. 

#include <stack>
#include <string>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::stack;

int main()
{
	string expression{ "This is (pezy) and (ocxs) over" };
	bool bSeen = false;
	stack<char> stk;
	int pos = 0, i = 0;
	for (const auto &s : expression)
	{
		++i;
		if (s == '(') { bSeen = true; pos = i; continue; }
		else if (s == ')')
		{
			bSeen = false;
			string repstr;
			while (!stk.empty())
			{
				repstr += stk.top();
				stk.pop();
			}

			expression.replace(pos, repstr.size(), repstr);
		}
		if (bSeen) stk.push(s);
	}

	cout << expression << endl;
    
    return 0;
}
