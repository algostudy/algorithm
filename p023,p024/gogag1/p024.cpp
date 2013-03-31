#include <iostream>

using namespace std;

int main()
{
	int NumOfCase=0;
	int i=0, j=0;

	cin >> NumOfCase;

	while(NumOfCase--){

		int nof=0; // Num Of Family
		int nop=0; // Num Of Person
		
		cin >> nof >> nop;

		int *p = new int[nof];
		
		p[0]=0;
		for(i=1; i<nof; i++)
			cin >> p[i];

		while(nop--){

			int a, b, bg, sm, bgp, smp, n=1;

			cin >> a >> b;
					
			bg = a>b?a:b;
			sm = a>b?b:a;

			if(bg==sm){
				cout << 0 << endl;
				continue;
			}

			bgp = p[bg];
			smp = sm;
			
			while(1){
				if(bgp > smp){
					bgp = p[bgp];
				}else if(bgp < smp){
					smp = p[smp];
				}else{
					break;
				}
				n++;
			}
	
			cout <<  n << endl;		
		}

		delete p;
	}

	return 0;
}
