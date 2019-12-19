#pragma once
#include<iostream>
template <class T>
struct TNode
{
	T val;
	TNode<T> *pNext;
};

template <class T>
class TStack
{
private:
	TNode<T> *pFirst;
public:
	TStack();
	~TStack();
	TStack(const TStack<T>& st);
	TStack<T>& operator=(const TStack<T>& st);
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(const T& a);
	T Pop();
	T Top();
	void Clear();
};

template <class T>//////////////////////////////////
TStack<T>::TStack()
{
	pFirst = NULL;
}

template <class T>
TStack<T>::~TStack()//////////////////
{
	TNode<T> *tmp = pFirst;
	while (pFirst!=NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}

template <class T>////////
TStack<T>::TStack(const TStack<T>& st)
{
	TNode<T> *tmp = st.pFirst;
	if (tmp==NULL)
	{
		pFirst = tmp;
	}
	while (tmp != NULL)
	{
		Push(tmp->val);
		tmp = tmp->pNext;
	}
	delete tmp;
}

template <class T>///////////
TStack<T>& TStack<T>::operator=(const TStack<T>& st)
{
	if (this != &st)
	{
		if (!IsEmpty())
		{
			Clear();
		}
		else
		{
			TNode<T> *tmp = st.pFirst;
			if (tmp == NULL)
			{
				pFirst = tmp;
			}
			while (tmp != NULL)
			{
				Push(tmp->val);
				tmp = tmp->pNext;
			}
			delete tmp;
		}
	}
	return *this;
}

template <class T>///////////////////////////
bool TStack<T>::IsEmpty()const {
	return pFirst == NULL;
}

template <class T>////////////////
bool TStack<T>::IsFull()const {
	TNode<T> *tmp;
	tmp = new TNode<T>;
	if (tmp==NULL)
	{
		return 1;
	}
	else
	{
		delete tmp;
		return 0;
	}
}

template <class T>//////////////////////////
void TStack<T>::Push(const T& a) {
	if (IsFull())
	{
		char e[] = "Stack is Full";
		throw e;
	}
	else
	{
		TNode<T> *tmp;
		tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		pFirst = tmp;
	}
}

template <class T>////////////////////////////////////
T TStack<T>::Pop() {
	if (IsEmpty())
	{
		char e[] = "Stack is Empty";
		throw e;
	}
	else
	{
		T res = pFirst->val;
		TNode<T> *tmp;
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}
}

template <class T>
T TStack<T>::Top() {/////////////////////////////////////
	if (IsEmpty())
	{
		char e[] = "Stack is Empty";
		throw e;
	}
	else
	{
		return pFirst->val;
	}
}

template <class T>////////////////////////////
void TStack<T>::Clear() {
	TNode<T> *tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}

}
