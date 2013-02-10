#include <iostream>

using namespace std;

void check(unsigned long int *res, int n, unsigned long int sum)
{
	if(sum==0)
	{
		res[n]++;
		return;
	}
	else if(sum==1)
		return;
	
	if(sum >= 2)
		check(res, n, sum-2);
	if(sum >= 3)
		check(res, n, sum-3);
	if(sum >= 5)
		check(res, n, sum-5);
}

void run(unsigned long int *res, int n)
{
	unsigned long int sum = n;
	
	check(res, n, sum);
}

int main()
{
	int i, n;
	unsigned long int res[101]={0,};

	for(i=1; i<7; i++)
		run(res, i);

	for(;i<101; i++)
		res[i] = res[i-2]+res[i-3]+res[i-5];
	
	while(1)
	{
		cin >> n;

		if(0==n)
			break;
	
		cout << res[n] << endl;	
	}
}
