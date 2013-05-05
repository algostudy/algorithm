#include <iostream>

using namespace std;

class stack {
public:
	stack();
	void push(int i);
	int pop();
	int size();
	int Top();
private:
	int data[2000];
	int top;
};

stack::stack(){
	top=0;
}

void stack::push(int i){
	data[++top]=i;
}

int stack::pop(){
	cout << data[top] << " ";
	return data[top--];
}

int stack::size(){

	cout << top << " ";
	return top;
}

int stack::Top(){
	cout << data[top] << " ";
	return data[top];
}

class queue {
public:
	queue();
	void enque(int i);
	int deque();
	int size();
	int Front();
private: 
	int data[2000];
	int front;
	int rear;
};

queue::queue(){
	front=0;
	rear=0;
}

void queue::enque(int i){
	data[++rear]=i;
}

int queue::deque(){
	cout << data[++front] << " ";
	return data[front];
}

int queue::size(){
	cout << rear-front << " ";
	return rear-front;
}

int queue::Front(){
	cout << data[++front] << " ";
	return data[front--];
}


int main()
{
	char qors;

	while(cin >> qors){

		if(qors == 'Q')
		{
			queue que;
			int num, i, j;
			cin >> num;
			for(i=0; i<num; i++)
			{
				cin >> j;
				que.enque(j);
			}
			
			cin >> num;
		
			for(i=0; i<num; i++)
			{
				char com;
				cin >> com;
				if(com == 'E')
				{
					cin >> j;
					que.enque(j);	
				}
				else if(com == 'D')
					que.deque();
				else if(com == 'S')
					que.size();
				else if(com == 'F')
					que.Front();
			}
		}
		else
		{
		
			stack st;
			int num, i, j;
			cin >> num;
			for(i=0; i<num; i++)
			{
				cin >> j;
				st.push(j);
			}
			
			cin >> num;
		
			for(i=0; i<num; i++)
			{
				char com;
				cin >> com;
				if(com == 'P')
				{
					cin >> j;
					st.push(j);	
				}
				else if(com == 'O')
					st.pop();
				else if(com == 'S')
					st.size();
				else if(com == 'T')
					st.Top();
			}
		}
		cout << endl;
	}
	
	return 0;
}
