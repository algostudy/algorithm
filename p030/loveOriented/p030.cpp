#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

void queue_func(int size)
{
		queue <int> que;
		string data;
		string value;
		int count;

		for(int i = 0; i < size; i++)
		{
				int value;
				cin >> value;
				//cout << " value " << value << endl;
				que.push(value);
		}

		//cout << endl;

		getline(cin, data);
		//cout << "line " << data << endl;
		getline(cin, data);
		//cout << "line " << data << endl;
		istringstream data_stream(data);
		data_stream >> count;
		//cout << "count " << count << endl;

		while( data_stream >> value )
		{
				//cout << "value " << value << endl;
				if(value.compare("E")== 0)
				{	
						data_stream >> value;
						int tempVal = atoi(value.c_str());
						que.push(tempVal);
				}
				else if(value.compare("D") == 0)
				{
						cout << que.front() << ' ';
						que.pop();
				}	
				else if(value.compare("S") == 0)
				{
						cout << que.size() << ' ';
				}
				else if(value.compare("F") == 0)
				{
						cout << que.front() << ' ';
				}	
		}
}

void stack_func(int size)
{
		stack <int> st;
		string data;
		string value;
		int count;

		for(int i = 0; i < size; i++)
		{
				int value;
				cin >> value;
				//cout << " value " << value << endl;
				st.push(value);
		}

		//cout << endl;

		getline(cin, data);
		//cout << "line " << data << endl;
		getline(cin, data);
		//cout << "line " << data << endl;
		istringstream data_stream(data);
		data_stream >> count;
		//cout << "count " << count << endl;

		while( data_stream >> value )
		{
				//cout << "value " << value << endl;

				if(value.compare("P")== 0)
				{	
						data_stream >> value;
						int tempVal = atoi(value.c_str());
						st.push(tempVal);
				}
				else if(value.compare("O") == 0)
				{
						cout << st.top() << ' ';
						st.pop();
				}	
				else if(value.compare("S") == 0)
				{
						cout << st.size() << ' ';
				}
				else if(value.compare("T") == 0)
				{
						cout << st.top() << ' ';
				}	
		}
}




int main(void)
{
		char mode;
		int size;




		while( cin >> mode )
		{
				//cout << mode << endl;
				cin >> size;
				//cout << size << endl;

				if(mode == 'Q')
				{
						queue_func(size);
				}
				else
				{
						stack_func(size);
				}

				cout << endl;
		}

		return 0;
}


