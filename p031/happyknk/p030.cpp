#include <stdio.h>
#include <stdlib.h>


void queue(int arr[2000], int size){
	int n = 0;
	char in;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		getchar();
		in = getchar();
		if(in == 'E'){
			scanf("%d", &(arr[size]));
			size++;
		}else if(in == 'D'){
			printf("%d ", arr[0]);
			for(int k=1; k<size; k++){
				arr[k-1] = arr[k];
			}
			size--;
		}else if(in == 'S'){
			printf("%d ", size);
		}else if(in == 'F'){
			printf("%d ", arr[0]);
		}
	}

	printf("\n");

}

void stack(int arr[2000], int size){
	int n = 0;
	char in;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		getchar();
		in = getchar();
		if(in == 'P'){
			scanf("%d", &(arr[size]));
			size++;
		}else if(in == 'O'){
			printf("%d ", arr[size-1]);
			size--;
		}else if(in == 'S'){
			printf("%d ", size);
		}else if(in == 'T'){
			printf("%d ", arr[size-1]);
		}
	}

	printf("\n");

}

int main(){

	char s;
	int size = 0;
	int arr[2000];
	int count = 0;

	while( count < 1000 ){
		count ++;
		s = getchar();
		scanf("%d", &size);

		for(int i=0; i<size; i++){
			scanf("%d", &arr[i]);
		}

		if( s == 'S' ){
			stack(arr, size);
		}else{
			queue(arr, size);
		}
		getchar();
	}
	return 0;
}

