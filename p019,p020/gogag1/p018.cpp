#include <iostream>

using namespace std;

#define MAX 100
#define DEBUG 1
void changeStack(int *data, int n)
{
	int cpData[MAX]={0,}, i=0, j=0;


	while(data[i]!=0)
	{
		cpData[i] = data[i++];
	}	

	for(i=n-1, j=0; i>=0; i--, j++)
	{
		data[j] = data[i++];
	}
}

void reverseStack(int *data, int n)
{
	int cpData[MAX]={0,}, i=0, j=0;

	while(data[i]!=0)
	{
		cpData[i] = data[i++];
	}	

	for(i=n-1, j=0; i>=0; i--, j++)
	{
		data[j] = cpData[i];
	}
	
	while(cpData[j]!=0)
	{
		data[j] = cpData[j];
		j++;
	}

	#ifndef DEBUG
	i=0;
	while(data[i]!=0)
	{
		cout << data[i] << " ";
		i++;
	}	
	#endif
}

int findMax(int *data, int n)
{
	int max=0, maxNum, i=0;

	while(data[i]!=0 && i<n)
	{
		if(data[i] > max)
		{
			max = data[i];
			maxNum = i;
		}

		i++;
	}

	return maxNum+1;
}

bool isSort(int *data)
{
	int i=1;

	while(data[i]!=0)
	{
		if(data[i]<data[i-1] && i<MAX)
			return false;
		i++;
	}
	
	return true;
}

int main()
{
	int data[MAX]={0,}, n=0, l=100;
	int i=0,j=0;
	char s[MAX];

	while(1){
		i=0;j=0; n=0;
		cin.getline(s,MAX);
		cout << s << endl;
		while(l--){
			if(s[i]==NULL)
				break;
			if(s[i]-'0'>0 && s[i]-'0'<100)
			{
				data[j++] = (int)(s[i]-'0');
				n++;
			}
			i++;
		}
		int N = n;
		j=1;
		while(n!=0 && !isSort(data)){
			l = findMax(data, n);
			if(l==1){
				cout << l << " ";
				reverseStack(data , N-j);
			}
			else if(l!=n){
					cout << N-l+1 << " ";
					reverseStack(data, l);
					
				//	reverseStack(data, j);
			}
			n--;
			j++;
		}
		cout << "0" << endl;
		#ifdef DEBUG
		i=0;
		while(data[i]!=0)
		{
			cout << data[i] << " ";
			i++;
		}	
		#endif
	
	}
}
