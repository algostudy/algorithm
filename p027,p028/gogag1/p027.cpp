#include <iostream>

using namespace std;

void recursive(int n)
{
	if(n<2)
		cout << n;
	else
	{
		recursive(n/2);
		cout << n%2;	
	}
}

int main()
{
	int numOfCase;

	cin >> numOfCase;

	while(numOfCase--){

		int input;

		cin >> input;

		recursive(input);

		cout << endl;
	}	
}
