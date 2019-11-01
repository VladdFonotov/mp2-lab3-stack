#pragma once
#include<iostream>
#include<string>
#include "Stack.h"

using namespace std;

class TCalculator
{
private:
	string expr;
	TStack<char> st_char;
public:
	TCalculator();
	~TCalculator() {};
	void SetExpr(string s);
	string GetExpr();
	bool check();
};

TCalculator::TCalculator() :st_char(100)
{
}



void TCalculator::SetExpr(string s)
{
	expr = s;
}

string TCalculator::GetExpr()
{
	return expr;
}

bool TCalculator::check() {
	st_char.Clear();
	for (int i = 0; i < expr.size(); i++)
	{
		if (expr[i] == '(')
		{
			st_char.Push(expr[i]);
		}
		if (expr[i] == ')')
		{
			if (st_char.IsEmpty())
			{
				return false;
			}
			else
			{
				st_char.Pop();
			}
		}
	}
	return st_char.IsEmpty();
}