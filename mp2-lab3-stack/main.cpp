#include <iostream>
#include"Calculator.h"

using namespace std;

int main() {
	string test;
	cin>> test;
	TCalculator C;
	C.SetExpr(test);
	cout << C.Calc()<<endl;
	system("pause");
	return 0;
	
}