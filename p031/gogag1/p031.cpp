#include <iostream>

using namespace std;

int main()
{
	int num;
	
	cin >> num;

	while(num--)
	{
		int n, mp, sum=0;

		cin >> n;
		cin >> mp;

		int *p = new int [n+1];

		while(mp--)
		{
			int h;
			cin >> h;
		
			for(int i=h; i<n+1; i+=h)
				p[i]=1;
		}

		for(int i=1; i<n+1; i++)
		{
			if(p[i]==1 && i%7!=0 && i%7!=6)
				sum++;
		}

		cout << sum << endl;
	}
}
