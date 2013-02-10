#include <stdio.h>
#include <stdlib.h>

int arr[101];

int youngkyu(int n){
	if(n<5){
		arr[n] = 1;
	}else if(n==5){
		arr[n] = 3;
	}else if(n==6){
		arr[n] = 2;
	}
}


int main(){
	int n = 0;

	while(scanf("%d", &n)){
		if(n==0) break;
		printf("%d\n", arr[n]);
	}

	return 0;
}
