/*
sin=s;
cos=c;
tan=t;
exp=e;
log=l;
arcsin=S;
arccos=C;
arctan=T;
sinh=n;
cosh=o;
tan=a;
*/
#pragma once
#define _USE_MATH_DEFINES

#include<iostream>
#include<string>
#include<math.h>
#include "Stack.h"
#include"fact.h"

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

TCalculator::TCalculator() :st_char(64),st_double(64)
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
	bool flag_un_op = 0;
	bool flag_sin = 0;
	char *tmp;
	double res;
	string str = "(";
	str += expr;
	str += ")";
	st_double.Clear();
	st_char.Clear();
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'p') {
			if (!strncmp(&str[i], "pi", 2)) {
				st_double.Push(M_PI);
				i = i + 2;
				flag_un_op = 0;
			}
		}
		if (str[i]=='a')
		{
			if (!strncmp(&str[i], "arcsin", 6)) {
				st_char.Push('S');
				i = i + 6;
			}
			if (!strncmp(&str[i], "arccos", 6)) {
				st_char.Push('C');
				i = i + 6;
			}
			if (!strncmp(&str[i], "arctan", 6)) {
				st_char.Push('T');
				i = i + 6;
			}
		}
		if (str[i] == 's'||str[i]=='c'||str[i]=='e'||str[i]=='t'||str[i]=='l')
		{
			if (!strncmp(&str[i], "log", 3)) {
				st_char.Push('l');
				i = i + 3;
			}
			if (str[i] == 's')
			{
				if (!strncmp(&str[i], "sinh", 4)) {
					st_char.Push('n');
					i = i + 4;
				}
				else
				{
					if (!strncmp(&str[i], "sin", 3)) {
						st_char.Push('s');
						i = i + 3;
					}
				}
			}
			if (str[i] == 'c')
			{
				if (!strncmp(&str[i], "cosh", 4)) {
					st_char.Push('o');
					i = i + 4;
				}
				else
				{
					if (!strncmp(&str[i], "cos", 3)) {
						st_char.Push('c');
						i = i + 3;
					}
				}
			}
			if (str[i] == 'e') {
				if (!strncmp(&str[i], "exp", 3)) {
					st_char.Push('e');
					i = i + 3;
				}
				else
				{
					st_double.Push(M_E);
					i ++;
					flag_un_op = 0;
				}
			}
			if (str[i] == 't')
			{
				if (!strncmp(&str[i], "tanh", 4)) {
					st_char.Push('a');
					i = i + 4;
				}
				else
				{
					if (!strncmp(&str[i], "tan", 3)) {
						st_char.Push('t');
						i = i + 3;
					}
				}
			}
		}
		if (str[i] == '!') {
			double temp_for_un_op = st_double.Pop();
			st_double.Push(fact(temp_for_un_op));
		}
		if (str[i]>='0' && str[i]<='9')
		{
			flag_un_op = 0;
			double d= strtod(&str[i], &tmp);
			int j =tmp-&str[i];
			i += j-1;
			st_double.Push(d);
		}
		if (str[i] == '(')
		{
			
			flag_un_op = 1;
			st_char.Push(str[i]);
		}
		if (str[i] == ')')
		{
			char tmpforop = st_char.Pop();
			while (tmpforop != '(')
			{
				if (st_double.IsEmpty()) {
					char e[] = "Not enough operands";
					throw e;
				}
				else
				{
					
					double op1, op2;
					op2 = st_double.Pop();
					switch (tmpforop)
					{
						case 's':
							st_double.Push(sin(op2));
							tmpforop = st_char.Pop(); break;
						case 'c':
							st_double.Push(cos(op2));
							tmpforop = st_char.Pop(); break;
						case 'e':
							st_double.Push(exp(op2));
							tmpforop = st_char.Pop(); break;
						case 't':
							st_double.Push(tan(op2));
							tmpforop = st_char.Pop(); break;
						case 'l':
							st_double.Push(log(op2));
							tmpforop = st_char.Pop(); break;
						case 'S':
							st_double.Push(asin(op2));
							tmpforop = st_char.Pop(); break;
						case 'C':
							st_double.Push(acos(op2));
							tmpforop = st_char.Pop(); break;
						case 'T':
							st_double.Push(atan(op2));
							tmpforop = st_char.Pop(); break;
						case 'n':
							st_double.Push(sinh(op2));
							tmpforop = st_char.Pop(); break;
						case 'o':
							st_double.Push(cosh(op2));
							tmpforop = st_char.Pop(); break;
						case 'a':
							st_double.Push(tanh(op2));
							tmpforop = st_char.Pop(); break;
						default:
						if (st_double.IsEmpty()) {
							char e[] = "Not enough operands";
							throw e;
						}
						else
						{
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
								st_double.Push(op1 / op2); break;
							case '^':
								st_double.Push(pow(op1, op2)); break;
							}
							tmpforop = st_char.Pop();
						}
					}
				}
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			if (flag_un_op == 1)
			{
				if (str[i]=='+'||str[i]=='-')
				{
					st_double.Push(0);
				}
				else
				{
					char e[] = "Uncorrect expressions";
					throw e;
				}
			}
			char tmpforop = st_char.Pop();
			while (Prior(str[i]) <= Prior(tmpforop))
			{
				if (st_double.IsEmpty()) {
					char e[] = "Not enough operands";
					throw e;
				}
				else
				{
					double op1, op2;
					op2 = st_double.Pop();
					switch (tmpforop)
					{
					case 's':
						st_double.Push(sin(op2));
						tmpforop = st_char.Pop(); break;
					case 'c':
						st_double.Push(cos(op2));
						tmpforop = st_char.Pop(); break;
					case 'e':
						st_double.Push(exp(op2));
						tmpforop = st_char.Pop(); break;
					case 't':
						st_double.Push(tan(op2));
						tmpforop = st_char.Pop(); break;
					case 'l':
						st_double.Push(log(op2));
						tmpforop = st_char.Pop(); break;
					case 'S':
						st_double.Push(asin(op2));
						tmpforop = st_char.Pop(); break;
					case 'C':
						st_double.Push(acos(op2));
						tmpforop = st_char.Pop(); break;
					case 'T':
						st_double.Push(atan(op2));
						tmpforop = st_char.Pop(); break;
					case 'n':
						st_double.Push(sinh(op2));
						tmpforop = st_char.Pop(); break;
					case 'o':
						st_double.Push(cosh(op2));
						tmpforop = st_char.Pop(); break;
					case 'a':
						st_double.Push(tanh(op2));
						tmpforop = st_char.Pop(); break;
					default:
						if (st_double.IsEmpty()) {
							char e[] = "Not enough operands";
							throw e;
						}
						else
						{
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
					}
				}
			}
			st_char.Push(tmpforop);
			st_char.Push(str[i]);
			
		}
	}
	return st_double.Pop();
}
