
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

TEST(TCalculator, cacl_function_works_correctly_with_plus_for_int)
{
	TCalculator c;
	c.SetExpr("5+7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 12);
}
TEST(TCalc, stop)
{
	system("pause");
}