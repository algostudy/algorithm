#include <iostream>

using namespace std;

void hanoi(int from, int temp, int to, int num)
{
	if(num == 1)
		cout << from << "->" << to <<endl;
	else
	{
		hanoi(from, to, temp, num-1);
		cout << from << "->" << to <<endl;
		hanoi(temp, from, to, num-1);
	}
}

int main()
{
	int num;
	
	while(1)
	{
		if(cin >> num)
		{
			hanoi(1,2,3,num);
			cout << endl;
		}
		else
			break;
	}
}
