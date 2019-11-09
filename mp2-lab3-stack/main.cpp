#include <iostream>
#include"Calculator.h"


using namespace std;

int main() {
	
	try {
		
		
		TCalculator C;
		string test_string;
		cin >> test_string;
		C.SetExpr(test_string);
		cout << C.Calc()<<endl;
	}
	catch (char *e)
	{
		cout << e<<endl;
	}

	system("pause");
	return 0;
	
}