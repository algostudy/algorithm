#include <iostream>

using namespace std;

int sum(int *b)
{
	int i, sum=0;

		cout << "sizeof(b) :" << sizeof(b) << " sizeofb[0] : " << sizeof(b[0]) << endl;
	for(i=0; i<(sizeof(b)/sizeof(b[0])); i++)
	{	
		cout << b[i] << " ";
		sum += b[i];
	}
	cout << endl;
	return sum;
}

int main()
{
	int a[4] = {1,2,3,4};
	int *b ;
	cout << sizeof(b) << endl;
		cout << "sizeof(a) :" << sizeof(a) << " sizeofa[0] : " << sizeof(a[0]) << endl;
	cout << sum(a) << endl;
	return 0;
}
