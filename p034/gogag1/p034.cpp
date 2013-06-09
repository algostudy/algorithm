#include <iostream>

using namespace std;

#define MAX 10000 
#define NOL 26 // Num Of Letter
#define SA 97 // Small A

int main()
{
	while(cin.eof() == false){
		
		int crtA[NOL] = {0,}, crtB[NOL] = {0,}; //crt = character
		char a[MAX]={0,}, b[MAX]={0,};	
		int i=0;

		cin >> a;
		cin >> b;

		for(i=0; i< MAX ; i++){
			if(a[i]==0 && b[i]==0)
				break;
		
			crtA[a[i]-SA]++;
			crtB[b[i]-SA]++;
		}

		for(i=0; i<NOL; i++)
		{
			if(crtA[i]>0 && crtB[i]>0)
			{
				if(crtA[i]>crtB[i])
					while(crtB[i]--)
						cout << (char)(i+SA);
				else
					while(crtA[i]--)
						cout << (char)(i+SA);
			}
		}

		cout << endl;
	}	

	return 0;
}
