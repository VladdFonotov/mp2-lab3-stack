#pragma once
#include<iostream>
#include<string>
#include "Stack.h"

using namespace std;

class TCalculator
{
private:
	string expr,postfix;
	TStack<char> st_char;
public:
	TCalculator();
	~TCalculator() {};
	void SetExpr(string s);
	string GetExpr();
	bool Check();
	int Prior(char c);
	void ToPostfix();
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

bool TCalculator::Check() {
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

int TCalculator::Prior(char c)
{
	if (c=='(')
	{
		return 0;
	}
	if (c == '+'||c=='-')
	{
		return 1;
	}
	if (c == '*' || c == '/')
	{
		return 2;
	}
	if (c == '^')
	{
		return 3;
	}
}

void TCalculator::ToPostfix() {
	string str = "(";
	str += expr;
	str += ")";
	st_char.Clear();
	postfix = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]=='(')
		{
			st_char.Push(str[i]);
		}
		if (str[i]>='0' && str[i]<='9'||str[i]=='.')
		{
			postfix += str[i];
		}
		if (str[i]==')')
		{
			char tmp = st_char.Pop();
			while (tmp!='(')
			{
				postfix += tmp;
				tmp = st_char.Pop();
			}
		}
		if (str[i]=='+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' )
		{
			postfix += " ";
			char tmp = st_char.Pop();
			while (Prior(str[i])<=Prior(tmp))
			{
				postfix += tmp;
				tmp = st_char.Pop();
			}
			st_char.Push(tmp);
			st_char.Push(str[i]);
		}
	}
}