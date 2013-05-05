#include <iostream>

using namespace std;

class Container
{
protected:
	int m_data[2000];

public:
	virtual int  size(void) = 0;
	virtual void push(int a_data) = 0;
	virtual int  pop(void) = 0;
	virtual int  get(void) = 0;
};

class Stack : public Container
{
private:
	int m_index;

public:
	Stack()
	{
		m_index = -1;
	}

	virtual int size(void)
	{
		return m_index + 1;
	}

	virtual void push(int a_data)
	{
		m_data[++m_index] = a_data;
	}

	virtual int pop(void)
	{
		return m_data[m_index--];
	}

	virtual int get(void)
	{
		return m_data[m_index];
	}
};

class Queue : public Container
{
private:
	int m_front;
	int m_rear;
	int m_size;

public:
	Queue()
	{
		m_size = m_front = m_rear = 0;
	}

	virtual int size(void)
	{
		return m_size;
	}

	virtual void push(int a_data)
	{

		m_data[m_rear] = a_data;
		m_rear = (m_rear + 1) % 2000;
		m_size++;
	}

	virtual int pop(void)
	{
		if ( m_front == m_rear )
			return -1;

		int ret = m_data[m_front];
		m_front = (m_front + 1) % 2000;
		m_size--;

		return ret;
	}

	virtual int get(void)
	{
		if ( m_front == m_rear )
			return -1;

		return m_data[m_front];
	}
};

int main(void)
{
	char container_type[256];
	char operation[256];
	int  n, m;
	int  element;

	Container* c;

	while ( scanf("%s", container_type) == 1 )
	{
		if ( container_type[0] == 'Q' )
			c = new Queue();
		else
			c = new Stack();

		scanf("%d", &n);
		for ( int i = 0; i < n; i++ )
		{
			scanf("%d", &element);
			c->push(element);
		}

		scanf("%d", &m);
		for ( int i = 0; i < m; i++ )
		{
			scanf("%s", operation);
			switch ( operation[0] )
			{
			case 'E':
			case 'P':
				scanf("%d", &element);
				c->push(element);
				break;

			case 'D':
			case 'O':
				printf("%d ", c->pop());
				break;

			case 'F':
			case 'T':
				printf("%d ", c->get());
				break;

			case 'S':
				printf("%d ", c->size());
				break;
			}
		}
		printf("\n");

		delete c;
	}
}
