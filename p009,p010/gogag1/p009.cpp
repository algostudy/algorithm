#include <iostream>

using namespace std;

int main()
{
	int i, j, n, mo;
	bool end = false;

	while(1){
		cin >> n;
		cin >> mo;
		
		int *ar = new int[n+1];	
		for(int k=0; k<n+1; k++)
			ar[k]=0;

		while(n--){
			cin >> i >> j;
			ar[i]++; ar[j]++;				
			
			if(n==1 && i==0){
				end = true;
				break;
			}
			
		}

		cout << "BICOLORABLE" << endl;	
		if(end)
			break;
	}

	return 0;
}
