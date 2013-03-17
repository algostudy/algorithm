#include <iostream>
#include <math.h>

using namespace std;

#define MAX 11

void initArr(int n, int *arr);
bool isPal(int *arr);
void addPal(int *arr);
unsigned int arrToi(int *arr);

int main()
{
	int n=0;

	cin >> n;

	while(n--){
		int arr[MAX]={0,};
		int i=0, num=0;
		unsigned int value=0;

		cin >> num;

		initArr(num, arr);
		while(1){
			if(isPal(arr))
				break;
			else
				addPal(arr);
			i++;
		}

		value =	arrToi(arr);

		cout << i << " " << value << endl;
	}

	return 0;
}


void initArr(int n, int *arr)
{
	int i=0;
	double dev;

	for(i=1; i<MAX; i++)
	{
		dev = pow(10.0,i);
		arr[i] = n%(int)dev;
		arr[i] /= (int)dev/10;

		if(n/(int)dev==0)
			break;
	}

	arr[0]=i;
}

void addPal(int *arr)
{
	int i, j, carry=0, n=0;

	if(arr[0]%2==0)
		n = arr[0]/2;
	else
		n = arr[0]/2 + 1;

	for(i=arr[0], j=1; j<=n ;i--,j++)
		arr[i] = arr[j] = arr[i] + arr[j];
	
	for(i=arr[0], j=1; j<=arr[0]; i--, j++)
	{
		if(j==10) break;

		if(arr[j] >= 20){
			arr[j] -= 20;
			carry = 2;
		}else if(arr[j] >= 10){
			arr[j] -= 10;
			carry = 1;
		}else
			carry = 0;

		arr[j+1] += carry;
	}
	
	if(carry==1)
		arr[0]++;
}

bool isPal(int *arr)
{
	int i=0, j=0;
	
	for(i=arr[0], j=1; j<=arr[0]; i--, j++)
	{
		if(arr[i] != arr[j])
			return false;
	}

	return true;
}

unsigned int arrToi(int *arr)
{
	unsigned int ret=0;
	int i=0;

	for(i=1; i<=arr[0]; i++)
	{
		ret += arr[i]*pow(10.0,i-1);
	}
	
	return ret;
}
