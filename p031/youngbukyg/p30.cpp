#include <iostream>
using namespace std;

class Stack
{
	int data;	
	int* top;

public:
	void push( int a ) 
	{
		*top = a;
		top++;	
	}
	
	int pop()
	{
		return &top;
	}
	
};


class Queue
{
	int data;
	int* front;
	int* rear;
public:
	void enque( int a ) 
	{
	i	*rear = a;
		rear++;
	}
	int deque()	
	{
		data = (*rear)--;
		return data;
	}
	int size()
	{
		return sizeof()
	}
	int top()
	{
	
	}
	

};


char GetInputs()
{
	char oper;	
	cin >> &oper;

	return oper; 
}
int GetInputs()
{
	char oper;	
	cin >> &oper;

	return oper; 
}

void int()
{
	int input;	
	Stack s = new int[];
	
	for(;;)
	{
		input = GetInputs()
		
		if( intput == \n )
			return 0;
	
		switch(input)		
		{
			case E:
				
		}

	}

}
