#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double total=0, avr=0, plus=0, minus=0, ps[1000]={0,};
	int i=0, num=0, temp=0;

	cin >> num;

	while(num > 0){
		
		temp = num;

		while(temp--){
			cin >> ps[i];
			total += ps[i++];
		}

		avr = floor((total/num)*100 + 0.5)/100;

		for(int j=0; j<num; j++)
		{
			if(ps[j] > avr)
				plus += ps[j] - avr;
			else
				minus += avr - ps[j];
		}

		if(plus > minus)
			cout << "$" << minus << endl;
		else
			cout << "$" << plus << endl;

		cin >> num;
		temp=0, total=0, avr=0, plus=0, minus=0;
		i=0;
	}

	return 0;
}
