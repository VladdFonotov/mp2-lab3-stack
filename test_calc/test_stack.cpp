#include "gtest.h"
#include"../mp2-lab3-stack/Stack.h"

TEST(TStack, cant_create_stack)
{
	ASSERT_NO_THROW(TStack<int> st());
}

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(3));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-3));
}

TEST(TStack, can_copy_stack)
{
	TStack<int> st1(5);
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.Push(i));
	}
	ASSERT_NO_THROW(TStack<int> st(st1));
}

TEST(TStack, can_equate_stacks_with_equal_size)
{
	TStack<int> st1(5);
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.Push(i));
	}
	TStack<int> st(5);
	ASSERT_NO_THROW(st=st1);
}

TEST(TStack, can_equate_stacks_with_different_size)
{
	TStack<int> st1(5);
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.Push(i));
	}
	TStack<int> st(10);
	ASSERT_NO_THROW(st = st1);
}

TEST(TStack, can_push_on_stack)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(st.Push(5));
	EXPECT_EQ(st.Pop(),5);
}

TEST(TStack, cant_push_on_full_stack)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);
	ASSERT_ANY_THROW(st.Push(5));
}

TEST(TStack, can_to_take_elem_from_stack)
{
	int d;
	TStack<int> st(5);
	st.Push(1);
	ASSERT_NO_THROW(d=st.Pop());
	EXPECT_EQ(1,d);
}

TEST(TStack, cant_to_take_elem_from_empty_stack)
{
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, can_check_empty_stack)
{
	TStack<int> st(5);
	EXPECT_EQ(st.IsEmpty(), 1);
}

TEST(TStack, can_check_full_stack)
{
	TStack<int> st(5);
	for (int i = 0; i <5; i++)
	{
		ASSERT_NO_THROW(st.Push(i));
	}
	EXPECT_EQ(st.IsFull(), 1);
}

TEST(TStack, can_clear_stack)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.Push(i));
	}
	st.Clear();
	EXPECT_EQ(st.IsEmpty(), 1);
}

TEST(TStack,trur_equalizatin_stacks)
{
	TStack<int> st(5);
	TStack<int> copy_st(7);
	for (int i = 0; i <5; i++)
	{
		ASSERT_NO_THROW(st.Push(i));
	}
	copy_st = st;
	for (int i = 4; i >=0; i--)
	{
		EXPECT_EQ(st.Pop(),i);
	}
}
TEST(TStack, can_check_top_elem_from_stack)
{
	TStack<int> st(5);
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.Push(i));
	}
	for (int i = 4; i >= 0; i--)
	{
		EXPECT_EQ(st.Top(), i);
		EXPECT_EQ(st.Pop(), i);
	}
}

TEST(TStack, stop)
{
	system("pause");
}
