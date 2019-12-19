#include "gtest.h"
#include"../mp2-lab3-stack/Stack_L.h"

TEST(TStack, cant_create_stack)
{
	ASSERT_NO_THROW(TStack<int> st);
}



TEST(TStack, can_copy_stack)
{
	TStack<int> st1;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.Push(i));
	}
	ASSERT_NO_THROW(TStack<int> st(st1));
}

TEST(TStack, can_equate_stacks_with_equal_size)
{
	TStack<int> st1;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.Push(i));
	}
	TStack<int> st;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.Push(i));
	}
	ASSERT_NO_THROW(st=st1);
}

TEST(TStack, can_equate_stacks_with_different_size)
{
	TStack<int> st1;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.Push(i));
	}
	TStack<int> st;
	for (int i = 0; i < 7; i++)
	{
		ASSERT_NO_THROW(st.Push(i));
	}
	ASSERT_NO_THROW(st = st1);
}

TEST(TStack, can_push_on_stack)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.Push(5));
	EXPECT_EQ(st.Pop(),5);
}


TEST(TStack, can_to_take_elem_from_stack)
{
	int d;
	TStack<int> st;
	st.Push(1);
	ASSERT_NO_THROW(d=st.Pop());
	EXPECT_EQ(1,d);
}

TEST(TStack, cant_to_take_elem_from_empty_stack)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, can_check_empty_stack)
{
	TStack<int> st;
	EXPECT_EQ(st.IsEmpty(), 1);
}


TEST(TStack, can_clear_stack)
{
	TStack<int> st;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.Push(i));
	}
	st.Clear();
	EXPECT_EQ(st.IsEmpty(), 1);
}

TEST(TStack,trur_equalizatin_stacks)
{
	TStack<int> st;
	TStack<int> copy_st;
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
	TStack<int> st;
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
