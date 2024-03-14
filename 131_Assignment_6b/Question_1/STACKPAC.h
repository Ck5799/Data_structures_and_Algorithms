#pragma once
#ifndef STACKPAC
#define STACKPAC
template <class T, int n>
class Stack
{
private: T Element[n];
	   int counter;
public:
	void clearStack()
	{
		counter = 0;
	}
	bool emptyStack()
	{
		return(counter == 0 ? true : false);
	}
	bool fullStack()
	{
		return(counter == 0 ? true : false);
	}
	void pushStack(T x)
	{
		Element[counter] = x;
		counter++;
	}
	T popStack()
	{
		counter--;
		return Element[counter];
	}
};
#endif