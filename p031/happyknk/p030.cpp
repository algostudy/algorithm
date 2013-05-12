#include <stdio.h>
#include <stdlib.h>


void queue(int arr[1000], int *size){
	int n = 0;
	char in;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%c", &in);
		if(in == 'E'){
			i++;
			scanf("%d", &arr[(*size)++]);
		}else if(in == 'D'){
			printf("%d ", arr[0]);
			for(int k=1; k<(*size); k++){
				arr[k-1] = arr[k];
			}
			(*size)--;
		}else if(in == 'S'){
			printf("%d ", *size);
		}else if(in == 'F'){
			printf("%d ", arr[0]);
		}
		printf("size %d\n", *size);
		for(int j=0; j<(*size); j++){
			printf("%d,", arr[j]);
		}

	}

	printf("\n");

}

void stack(int arr[1000], int *size){
	int n = 0;
	char in;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%c", &in);
		if(in == 'P'){
			i++;
			scanf("%d", &arr[(*size)++]);
		}else if(in == 'O'){
			printf("%d ", arr[(*size)-1]);
			(*size)--;
		}else if(in == 'S'){
			printf("%d ", *size);
		}else if(in == 'T'){
			printf("%d ", arr[(*size)-1]);
		}

		for(int j=0; j<(*size); j++){
			printf("%d", arr[j]);
		}

	}

	printf("\n");

}

int main(){

	char s;
	int size = 0;
	int arr[1000];
	int count = 0;

	while( count++ < 1000 ){
		scanf("%c %d", &s, &size);

		for(int i=0; i<size; i++){
			scanf("%d", &arr[i]);
		}

		if( s == 'S' ){
			stack(arr, &size);
		}else{
			queue(arr, &size);
		}

	}
	return 0;
}

