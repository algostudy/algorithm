#include <iostream>

using namespace std;

int main()
{
	int numOfCase, i, a, b, sumA, sumB;

	while(cin >> numOfCase){
		
		cin >> a;

		for(i=0; i<numOfCase-1; i++){
			cin >> b;
			sumA += a>b?a-b:b-a;
			a = b;
			sumB += i;
		}

		sumB += numOfCase-1;

		if(sumA == sumB)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}

	return 0;
}
