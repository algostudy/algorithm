#include <iostream>
#include <sstream>

using namespace std;


void quick(int *arr, int num)
{
	if(num < 2)
		return;

	int pivot=arr[0], i=0, j=num, temp=0;

	while( i<j){
		for(i=0; i<num; )
			if(arr[++i] > pivot)
				break;

		for(j=num; j>=0;)
			if(arr[--j] < pivot)
				break;

		cout << "i = " << i << ", sibal j= " << j << endl;
		if(i<j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
			break;
		cout << "i = " << i << ", j= " << j << endl;
	}

	arr[0] = arr[j];
	arr[j] = pivot;

	for(int t=0; t<num; t++)
		cout << arr[t++] << endl;


	//quick(arr, j - 1);
	//quick(arr+j + 1, num-j - 1);
			
}

int main()
{
	int arr[100000]={0,};
	int i=0, numOfCase=1;

	cin >> numOfCase;
	

	while(numOfCase--){
		i=0;
		int num;
		cin >> num;
	//	arr[num] = '\n';

	//	istringstream iss(str);
		
		for(int j=0; j<num; j++)
			cin >> arr[j++];

		cout << "num = " << num << endl;
		quick(arr, num);

		for(int j=0; j<num; j++)
			cout << arr[j++];

		
	}
	
	return 0;
}
