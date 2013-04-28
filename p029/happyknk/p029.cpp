#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void Quick(int* data, int size){

	int pivot = data[0];
	int left = 0;
	int right = size;

	if(size < 2) return;

	while ( 1 ) {

		while ( data[++left] < pivot )
			; // blank

		while ( data[--right] > pivot )
			; // blank

		if ( left < right ){
			int temp = data[left];
			data[left] = data[right];
			data[right] = temp;	
		}else
			break;
	}
	
	int tmp = data[0];
	data[0] = data[right];
	data[right] = tmp;

	Quick(data, right);
	Quick(data+right+1, size-right-1); 

}


int main(){

	int n = 0;
	static int data[100000];

	scanf("%d", &n);

	while(n-->0){

		int count = 0;
		scanf("%d", &count);
		for(int i=0; i<count; i++){
			scanf("%d", &data[i]);
		}

		Quick(data, count);

		for ( int i = 0; i < count; i++ )
			printf("%d ", data[i]);
	printf("\n");

	}


	return 0;
}
