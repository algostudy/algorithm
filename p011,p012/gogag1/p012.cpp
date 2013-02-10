#include <iostream>
#include <math.h>

using namespace std;

typedef struct coordinate{
	int coor_x;
	int coor_y;
	int value;
} Coordinate;

int main()
{
	int n, data, nSquare, n1Square;
	Coordinate left, down;
	int i, j, k;
	bool isOdd = false;
	while(1)
	{
		cin >> data;

		if(0 == data)
			break;

		n = (int)sqrt((double)data);
		isOdd = n%2==1?true:false;
		
		nSquare = n*n;
		n1Square = (n+1)*(n+1);
		
		if(!(nSquare==data)){
			left.coor_x = 1;
			left.coor_y = n+1;
		
			down.coor_x = n+1;
			down.coor_y = 1;

			if(isOdd) 
			{
				left.value = nSquare + 1;
				down.value = n1Square;
				
				i = data - left.value;
				j = down.value - data;
			}
			else 
			{
				left.value = n1Square;
				down.value = nSquare + 1;
				
				i = left.value - data;
				j = data - down.value;
			}
	

			if(i<=j)
			{
				left.coor_x += i;
				left.value = data;
			}
			else 
			{
				down.coor_y += j;
				down.value = data;
			}
		}
		else{
			if(isOdd)
			{
				left.coor_x=n;
				left.coor_y=1;
				left.value = nSquare;
			}
			else
			{
				down.coor_x=1;
				down.coor_y=n;
				down.value=nSquare;
			}
		}
	
		if(data == left.value)
			cout << left.coor_x << " " << left.coor_y << endl;
		else
			cout << down.coor_x << " " << down.coor_y << endl;
	}	
}
