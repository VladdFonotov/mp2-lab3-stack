#pragma once
#include <iostream>

double fact(int n) {
	if (n < 0)
	{
		char e[] = "Uncorrect expressions";
		throw e;
	}
	else
	{
		if (n == 0)
		{
			return 1;
		}
		else
		{
			return(n*fact(n - 1));
		}
	}
}