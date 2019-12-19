#include "gtest.h"
#include"../mp2-lab3-stack/Calculator.h"


TEST(TCalculator, can_create_calc)
{
  ASSERT_NO_THROW(TCalculator c);
}

TEST(TCalculator, can_set_expr)
{
	TCalculator c;
	ASSERT_NO_THROW(c.SetExpr("2+2"));
	EXPECT_EQ(c.GetExpr(), "2+2");
}

TEST(TCalculator, can_get_expr)
{
	TCalculator c;
	ASSERT_NO_THROW(c.SetExpr("2+2"));
	ASSERT_NO_THROW(c.GetExpr());
	EXPECT_EQ(c.GetExpr(), "2+2");
}

TEST(TCalculator, check_function_works_correctly)
{
	TCalculator c;
	c.SetExpr("((2)+(2))");
	ASSERT_NO_THROW(c.Check());
	EXPECT_EQ(c.Check(), 1);
	c.SetExpr("(2)+(2))");
	ASSERT_NO_THROW(c.Check());
	EXPECT_EQ(c.Check(), 0);
}

TEST(TCalculator, un_minus_works_correctly)
{
	TCalculator c;
	c.SetExpr("-5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),-5);
	c.SetExpr("-3.14");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -3.14);
	c.SetExpr("-0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0);
	c.SetExpr("-(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -0.5);
}

TEST(TCalculator, cacl_function_works_correctly_with_plus_for_int)
{
	TCalculator c;
	c.SetExpr("5+7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5+7);
	c.SetExpr("0+7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),7);
}

TEST(TCalculator, cacl_function_works_correctly_with_plus_for_double)
{
	TCalculator c;
	c.SetExpr("1/2+1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1);
	c.SetExpr("0+1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),0.5);
	c.SetExpr("1/2+1/4");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.0/ 2) + (1.0/ 4);
	EXPECT_EQ(c.Calc(),sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_minus_for_int)
{
	TCalculator c;
	c.SetExpr("5-7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 - 7);
	c.SetExpr("7-2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 7-2);
	c.SetExpr("0-7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),-7);
}

TEST(TCalculator, cacl_function_works_correctly_with_minus_for_double)
{
	TCalculator c;
	c.SetExpr("1/2-1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0);
	c.SetExpr("0-1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),-0.5);
	c.SetExpr("1/2-1/4");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.0 / 2) -(1.0 / 4);
	EXPECT_EQ(c.Calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_mult_for_int)
{
	TCalculator c;
	c.SetExpr("5*7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5*7);
	c.SetExpr("0*7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0*7);
	c.SetExpr("5*(-7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5*(-7));
}

TEST(TCalculator, cacl_function_works_correctly_with_mult_for_double)
{
	TCalculator c;
	c.SetExpr("1/2*1/2");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.0 / 2) * (1.0 / 2);
	EXPECT_EQ(c.Calc(),sum);
	c.SetExpr("0*1/2");
	ASSERT_NO_THROW(c.Calc());
	 sum = 0*(1.0/2);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("1/2*(-1/4)");
	ASSERT_NO_THROW(c.Calc());
	 sum = ((1.0 / 2) * (-(1.0 / 4)));
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("1*1/2");
	ASSERT_NO_THROW(c.Calc());
	 sum = 1 * (1.0 / 2);
	EXPECT_EQ(c.Calc(),sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_div_for_int)
{
	TCalculator c;
	c.SetExpr("5/7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5.0/ 7);
	c.SetExpr("0/7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0 / 7);
	c.SetExpr("5/(-7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5.0/ (-7));
	c.SetExpr("5/0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),INFINITY);
}

TEST(TCalculator, cacl_function_works_correctly_with_diff_op_for_double)
{
	TCalculator c;
	c.SetExpr("(1.1/2)/(1/2.1)");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.1 / 2) / (1.0 / 2.1);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("0/(1/2.1)");
	ASSERT_NO_THROW(c.Calc());
	sum = (0 / (1/(2.1)));
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(1/2.3)/(-1/4.4)");
	ASSERT_NO_THROW(c.Calc());
	sum = ((1.0 / 2.3) / (-(1.0 / 4.4)));
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("1/(1/2.1)");
	ASSERT_NO_THROW(c.Calc());
	sum = 1 / (1.0 / 2.1);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(1/5.1)/0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), INFINITY);
}

TEST(TCalculator, cacl_function_works_correctly_with_vozv_v_step_for_int)
{
	TCalculator c;
	c.SetExpr("5^0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),1);
	c.SetExpr("0^5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),0);
	c.SetExpr("5^2");
	ASSERT_NO_THROW(c.Calc());
	double sum =pow(5,2);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("5^(-2)");
	ASSERT_NO_THROW(c.Calc());
	sum =pow(5,-2);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(-2)^5");
	ASSERT_NO_THROW(c.Calc());
	sum =pow( (-2) , 5);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(-2)^4");
	ASSERT_NO_THROW(c.Calc());
	sum = pow((-2),4);
	EXPECT_EQ(c.Calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_for_diff_alg_op) {
	TCalculator c;
	double res;
	c.SetExpr("(5+5)*5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 50);
	c.SetExpr("5+5*5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),30);
	c.SetExpr("(5+5)/5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 2);
	c.SetExpr("5+5/5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 6);
	c.SetExpr("5+5^2/5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5+pow(5,2)/5);
	c.SetExpr("5/5+(2^5-1+8*7)-1");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), ((5 / 5) + ((pow(2,5)) - 1 + 8 * 7) - 1));
}

TEST(TCalculator, cacl_function_works_correctly_for_fact) {
	TCalculator c;
	c.SetExpr("5!");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),fact(5));
	c.SetExpr("3!!");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), fact(fact(3)));
	c.SetExpr("0!");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), fact(0));
	c.SetExpr("(3+2)!");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), fact(5));
	c.SetExpr("3+3!");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),3+fact(3));
	c.SetExpr("1/5!");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1/fact(5));
	c.SetExpr("3+(3+1)!");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 3 + fact(3+1));
	c.SetExpr("(3+1)!+3");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 3 + fact(3 + 1));
	c.SetExpr("((3*2)+1)!+3");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 3 + fact((3*2) + 1));
}

TEST(TCalculator, cacl_function_works_correctly_for_abs) {
	TCalculator c;
	c.SetExpr("abs(5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), abs(5));
	c.SetExpr("abs(3!)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), abs(fact(3)));
	c.SetExpr("abs(0)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), abs(0));
	c.SetExpr("abs(5+3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), abs(8));
	c.SetExpr("abs(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5);
	c.SetExpr("(abs((-2)^3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 8);
	c.SetExpr("(abs(5-7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 2);
	c.SetExpr("(5+abs(5-7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 7);
	c.SetExpr("(-5+abs(5-7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -3);
	c.SetExpr("(5+abs(5-7)+10");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 17);
}

TEST(TCalculator, cacl_function_works_correctly_for_pi) {
	TCalculator c;
	c.SetExpr("pi");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), M_PI);
	c.SetExpr("-pi");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),-M_PI);
	c.SetExpr("pi+1");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),M_PI+1);
	c.SetExpr("1+pi");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), M_PI + 1);
	c.SetExpr("2*pi");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 2*M_PI);
	c.SetExpr("2/pi");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 2 / M_PI);
	c.SetExpr("pi^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow( M_PI,2));
	c.SetExpr("2^pi");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(2,M_PI));
}

TEST(TCalculator, cacl_function_works_correctly_for_e) {
	TCalculator c;
	c.SetExpr("e");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), M_E);
	c.SetExpr("-e");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -M_E);
	c.SetExpr("e+1");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), M_E + 1);
	c.SetExpr("1+e");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), M_E + 1);
	c.SetExpr("2*e");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 2 * M_E);
	c.SetExpr("2/e");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 2 / M_E);
	c.SetExpr("e^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(M_E, 2));
	c.SetExpr("2^e");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(2, M_E));
}

TEST(TCalculator, cacl_function_works_correctly_for_sin) {
	TCalculator c;
	c.SetExpr("sin(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(1));
	c.SetExpr("sin(pi/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(M_PI/2));
	c.SetExpr("sin(e^2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(pow(M_E,2)));
	c.SetExpr("1+sin(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),1+sin(1));
	c.SetExpr("sin(-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(-1));
	c.SetExpr("sin(1+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(2));
	c.SetExpr("sin(1-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0);
	c.SetExpr("1/(sin(1))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1/(sin(1)));
	c.SetExpr("5*sin(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5*sin(1));
	c.SetExpr("(5*sin(1))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * sin(1),2));
	c.SetExpr("(5*sin(5^2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * sin(pow(5, 2)));
	c.SetExpr("sin(3!)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),sin(fact(3)));
	c.SetExpr("(sin(5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(sin(5), -5));
	c.SetExpr("sin(5+1)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(5+1)+100);
	c.SetExpr("100+sin(5+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),sin(5 + 1) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_cos) {
	TCalculator c;
	c.SetExpr("cos(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(1));
	c.SetExpr("cos(pi/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(M_PI/ 2));
	c.SetExpr("cos(e^2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(pow(M_E ,2)));
	c.SetExpr("1+cos(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),1+cos(1));
	c.SetExpr("cos(-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(-1));
	c.SetExpr("cos(1+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(2));
	c.SetExpr("cos(1-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(0));
	c.SetExpr("1/(cos(1))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (cos(1)));
	c.SetExpr("5*cos(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * cos(1));
	c.SetExpr("(5*cos(1))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * cos(1), 2));
	c.SetExpr("(5*cos(5^2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * cos(pow(5, 2)));
	c.SetExpr("cos(3!)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(fact(3)));
	c.SetExpr("(cos(5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(cos(5), -5));
	c.SetExpr("cos(5+1)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(5 + 1) + 100);
	c.SetExpr("100+cos(5+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(5 + 1) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_tan) {
	TCalculator c;
	c.SetExpr("tan(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(1));
	c.SetExpr("tan(pi/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(M_PI / 2));
	c.SetExpr("tan(e^2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(pow(M_E, 2)));
	c.SetExpr("1+tan(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + tan(1));
	c.SetExpr("tan(-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(-1));
	c.SetExpr("tan(1+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(2));
	c.SetExpr("tan(1-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(0));
	c.SetExpr("1/(tan(1))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (tan(1)));
	c.SetExpr("5*tan(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 *tan(1));
	c.SetExpr("(5*tan(1))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * tan(1), 2));
	c.SetExpr("(5*tan(5^2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * tan(pow(5, 2)));
	c.SetExpr("tan(3!)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(fact(3)));
	c.SetExpr("(tan(5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(tan(5), -5));
	c.SetExpr("tan(5+1)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(5 + 1) + 100);
	c.SetExpr("100+tan(5+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(5 + 1) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_exp) {
	TCalculator c;
	c.SetExpr("exp(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(1));
	c.SetExpr("exp(pi/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(M_PI / 2));
	c.SetExpr("exp(e^2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(pow(M_E, 2)));
	c.SetExpr("1+exp(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + exp(1));
	c.SetExpr("exp(-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(-1));
	c.SetExpr("exp(1+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(2));
	c.SetExpr("exp(1-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(0));
	c.SetExpr("1/(exp(1))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (exp(1)));
	c.SetExpr("5*exp(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * exp(1));
	c.SetExpr("(5*exp(1))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * exp(1), 2));
	c.SetExpr("(5*exp(5^2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * exp(pow(5, 2)));
	c.SetExpr("exp(3!)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(fact(3)));
	c.SetExpr("(exp(5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(exp(5),-5));
	c.SetExpr("exp(5+1)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(5 + 1) + 100);
	c.SetExpr("100+exp(5+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), exp(5 + 1) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_log) {
	TCalculator c;
	c.SetExpr("log(1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0);
	c.SetExpr("log(pi/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(M_PI / 2));
	c.SetExpr("log(e^2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(pow(M_E, 2)));
	c.SetExpr("1+log(2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + log(2));
	c.SetExpr("log(51)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(51));
	c.SetExpr("log(1+2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(3));
	c.SetExpr("log(5-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(5-1));
	c.SetExpr("1/(log(5))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (log(5)));
	c.SetExpr("5*log(5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * log(5));
	c.SetExpr("(5*log(5))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * log(5), 2));
	c.SetExpr("(5*log(5^2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 *log(pow(5, 2)));
	c.SetExpr("log(3!)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(fact(3)));
	c.SetExpr("(log(5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(log(5), -5));
	c.SetExpr("log(5+1)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(5 + 1) + 100);
	c.SetExpr("100+log(5+1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), log(5 + 1) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_arcsin) {
	TCalculator c;
	c.SetExpr("arcsin(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(1.0/2));
	c.SetExpr("arcsin(pi/4)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(M_PI / 4));
	c.SetExpr("arcsin(e^(-2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(pow(M_E,-2)));
	c.SetExpr("1+arcsin(1/3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + asin(1.0/3));
	c.SetExpr("arcsin(-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(-1.0/2));
	c.SetExpr("arcsin((1/2)+(1/4))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin((1.0/2)+(1.0/4)));
	c.SetExpr("arcsin(1/2-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(0));
	c.SetExpr("1/(arcsin(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (asin(1.0/2)));
	c.SetExpr("5*arcsin(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * asin(1.0/2));
	c.SetExpr("(5*arcsin(1/2))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * asin(1.0/2), 2));
	c.SetExpr("(5*arcsin(5^(-2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * asin(pow(5, -2)));
	c.SetExpr("arcsin(1/(3!))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(1/fact(3)));
	c.SetExpr("(arcsin(1/5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(asin(1.0/5), -5));
	c.SetExpr("arcsin(1/8+1/7)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(1.0/8+ 1.0/7) + 100);
	c.SetExpr("100+arcsin(1/8+1/7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), asin(1.0/8 + 1.0/7) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_arccos) {
	TCalculator c;
	c.SetExpr("arccos(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(1.0 / 2));
	c.SetExpr("arccos(pi/4)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(M_PI / 4));
	c.SetExpr("arccos(e^(-2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(pow(M_E, -2)));
	c.SetExpr("1+arccos(1/3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + acos(1.0 / 3));
	c.SetExpr("arccos(-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(-1.0 / 2));
	c.SetExpr("arccos((1/2)+(1/4))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos((1.0 / 2) + (1.0 / 4)));
	c.SetExpr("arccos(1/2-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(0));
	c.SetExpr("1/(arccos(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (acos(1.0 / 2)));
	c.SetExpr("5*arccos(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * acos(1.0 / 2));
	c.SetExpr("(5*arccos(1/2))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * acos(1.0 / 2), 2));
	c.SetExpr("(5*arccos(5^(-2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * acos(pow(5, -2)));
	c.SetExpr("arccos(1/(3!))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(1 / fact(3)));
	c.SetExpr("(arccos(1/5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(acos(1.0 / 5), -5));
	c.SetExpr("arccos(1/8+1/7)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(1.0 / 8 + 1.0 / 7) + 100);
	c.SetExpr("100+arccos(1/8+1/7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), acos(1.0 / 8 + 1.0 / 7) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_arctan) {
	TCalculator c;
	c.SetExpr("arctan(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(1.0 / 2));
	c.SetExpr("arctan(pi/4)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(M_PI / 4));
	c.SetExpr("arctan(e^(-2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(pow(M_E, -2)));
	c.SetExpr("1+arctan(1/3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + atan(1.0 / 3));
	c.SetExpr("arctan(-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(-1.0 / 2));
	c.SetExpr("arctan((1/2)+(1/4))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan((1.0 / 2) + (1.0 / 4)));
	c.SetExpr("arctan(1/2-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(0));
	c.SetExpr("1/(arctan(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (atan(1.0 / 2)));
	c.SetExpr("5*arctan(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * atan(1.0 / 2));
	c.SetExpr("(5*arctan(1/2))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * atan(1.0 / 2), 2));
	c.SetExpr("(5*arctan(5^(-2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * atan(pow(5, -2)));
	c.SetExpr("arctan(1/(3!))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(1 / fact(3)));
	c.SetExpr("(arctan(1/5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(atan(1.0 / 5), -5));
	c.SetExpr("arctan(1/8+1/7)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(1.0 / 8 + 1.0 / 7) + 100);
	c.SetExpr("100+arctan(1/8+1/7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), atan(1.0 / 8 + 1.0 / 7) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_sinh) {
	TCalculator c;
	c.SetExpr("sinh(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(1.0 / 2));
	c.SetExpr("sinh(pi/4)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(M_PI / 4));
	c.SetExpr("sinh(e^(-2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(pow(M_E, -2)));
	c.SetExpr("1+sinh(1/3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + sinh(1.0 / 3));
	c.SetExpr("sinh(-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(-1.0 / 2));
	c.SetExpr("sinh((1/2)+(1/4))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh((1.0 / 2) + (1.0 / 4)));
	c.SetExpr("sinh(1/2-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(0));
	c.SetExpr("1/(sinh(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (sinh(1.0 / 2)));
	c.SetExpr("5*sinh(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * sinh(1.0 / 2));
	c.SetExpr("(5*sinh(1/2))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * sinh(1.0 / 2), 2));
	c.SetExpr("(5*sinh(5^(-2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * sinh(pow(5, -2)));
	c.SetExpr("sinh(1/(3!))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(1 / fact(3)));
	c.SetExpr("(sinh(1/5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(sinh(1.0 / 5), -5));
	c.SetExpr("sinh(1/8+1/7)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(1.0 / 8 + 1.0 / 7) + 100);
	c.SetExpr("100+sinh(1/8+1/7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sinh(1.0 / 8 + 1.0 / 7) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_cosh) {
	TCalculator c;
	c.SetExpr("cosh(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(1.0 / 2));
	c.SetExpr("cosh(pi/4)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(M_PI / 4));
	c.SetExpr("cosh(e^(-2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(pow(M_E, -2)));
	c.SetExpr("1+cosh(1/3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + cosh(1.0 / 3));
	c.SetExpr("cosh(-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(-1.0 / 2));
	c.SetExpr("cosh((1/2)+(1/4))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh((1.0 / 2) + (1.0 / 4)));
	c.SetExpr("cosh(1/2-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(0));
	c.SetExpr("1/(cosh(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (cosh(1.0 / 2)));
	c.SetExpr("5*cosh(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * cosh(1.0 / 2));
	c.SetExpr("(5*cosh(1/2))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * cosh(1.0 / 2), 2));
	c.SetExpr("(5*cosh(5^(-2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * cosh(pow(5, -2)));
	c.SetExpr("cosh(1/(3!))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(1 / fact(3)));
	c.SetExpr("(cosh(1/5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(cosh(1.0 / 5), -5));
	c.SetExpr("cosh(1/8+1/7)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(1.0 / 8 + 1.0 / 7) + 100);
	c.SetExpr("100+cosh(1/8+1/7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cosh(1.0 / 8 + 1.0 / 7) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_tanh) {
	TCalculator c;
	c.SetExpr("tanh(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(1.0 / 2));
	c.SetExpr("tanh(pi/4)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(M_PI / 4));
	c.SetExpr("tanh(e^(-2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(pow(M_E, -2)));
	c.SetExpr("1+tanh(1/3)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + tanh(1.0 / 3));
	c.SetExpr("tanh(-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(-1.0 / 2));
	c.SetExpr("tanh((1/2)+(1/4))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh((1.0 / 2) + (1.0 / 4)));
	c.SetExpr("tanh(1/2-1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(0));
	c.SetExpr("1/(tanh(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 / (tanh(1.0 / 2)));
	c.SetExpr("5*tanh(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * tanh(1.0 / 2));
	c.SetExpr("(5*tanh(1/2))^2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(5 * tanh(1.0 / 2), 2));
	c.SetExpr("(5*tanh(5^(-2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * tanh(pow(5, -2)));
	c.SetExpr("tanh(1/(3!))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(1 / fact(3)));
	c.SetExpr("(tanh(1/5))^(-5)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(tanh(1.0 / 5), -5));
	c.SetExpr("tanh(1/8+1/7)+100");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(1.0 / 8 + 1.0 / 7) + 100);
	c.SetExpr("100+tanh(1/8+1/7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tanh(1.0 / 8 + 1.0 / 7) + 100);
}

TEST(TCalculator, cacl_function_works_correctly_for_trig_func) {
	TCalculator c;
	c.SetExpr("sin(sin(sin(1/2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(sin(sin((1.0 / 2)))));
	c.SetExpr("cos(cos(cos(1/2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(cos(cos((1.0 / 2)))));
	c.SetExpr("sin(cos(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(cos((1.0 / 2))));
	c.SetExpr("cos(sin(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), cos(sin((1.0 / 2))));
	c.SetExpr("tan(tan(tan(1/2)))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(tan(tan((1.0 / 2))))); 
	c.SetExpr("sin(tan(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), sin(tan(0.5)));
	c.SetExpr("tan(sin(1/2))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), tan(sin(0.5)));
	c.SetExpr("arcsin((arccos(1/32))^(-5))");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),asin(pow(acos(1.0 / 32), -5)));
}

TEST(TCalculator, cacl_function_works_correctly_for_all_func) {
	TCalculator c;
	c.SetExpr("1+((exp(5)+sin(1)-sin(3!))/(5!))^(-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(),1+(pow((exp(5)+sin(1)-sin(fact(3)))/(fact(5)),-1)));
	c.SetExpr("1+((exp(5)+arcsin(1/2)-sinh(3!))/(5!))^(-1)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1 + (pow((exp(5) + asin(1.0/2) - sinh(fact(3))) / (fact(5)), -1)));
	c.SetExpr("(arcsin(sin(5))+5!)^(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), pow(asin(sin(5))+fact(5),1.0/2));
}

TEST(TCalc, stop)
{
	system("pause");
}