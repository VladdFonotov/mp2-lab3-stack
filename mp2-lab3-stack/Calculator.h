#pragma once
#include<iostream>
#include<string>
#include<math.h>
#include "Stack.h"

using namespace std;

class TCalculator
{
private:
	string expr;
	TStack<char> st_char;
	TStack<double> st_double;
public:
	TCalculator();
	~TCalculator() {};
	void SetExpr(string s);
	string GetExpr();
	bool Check();
	int Prior(char c);
	double Calc();
};

TCalculator::TCalculator() :st_char(50),st_double(50)
{
}

void TCalculator::SetExpr(string _expr)
{
	expr = _expr;
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

double TCalculator::Calc(){
	char *tmp;
	double res;
	string str = "(";
	str += expr;
	str += ")";
	st_double.Clear();
	st_char.Clear();
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]>='0' && str[i]<='9')
		{
			double d= strtod(&str[i], &tmp);
			int j =tmp-&str[i];
			i += j-1;
			st_double.Push(d);
		}
		if (str[i] == '(')
		{
			st_char.Push(str[i]);
		}
		if (str[i] == ')')
		{
			char tmpforop = st_char.Pop();
			while (tmpforop != '(')
			{
				double op1, op2;
				op2 = st_double.Pop();
				op1 = st_double.Pop();
				switch (tmpforop)
				{
				case '+':
					st_double.Push(op1 + op2); break;
				case '-':
					st_double.Push(op1 - op2); break;
				case '*':
					st_double.Push(op1 * op2); break;
				case '/':
					st_double.Push (op1 / op2); break;
				case '^':
					st_double.Push(pow(op1, op2)); break;
				}
				tmpforop = st_char.Pop();
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			char tmpforop = st_char.Pop();
			while (Prior(str[i]) <= Prior(tmpforop))
			{
				double op1, op2;
				op2 = st_double.Pop();
				op1 = st_double.Pop();
				switch (tmpforop)
				{
				case '+':
					res = op1 + op2; break;
				case '-':
					res = op1 - op2; break;
				case '*':
					res = op1 * op2; break;
				case '/':
					res = op1 / op2; break;
				case '^':
					res = pow(op1, op2); break;
				}
				st_double.Push(res);
				tmpforop = st_char.Pop();
			}
			st_char.Push(tmpforop);
			st_char.Push(str[i]);
			
		}
	}
	return st_double.Pop();
}
