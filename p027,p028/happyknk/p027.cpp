#include <stdio.h>
#include <stdlib.h>

void binary(int dec){
	if( dec < 2){ 
		printf("%d", dec);
		return;
	}
	binary(dec/2);
	printf("%d", dec%2);
}

int main(){
	
	int n = 0;

	scanf("%d", &n);
	while( n-- > 0 ){
		int dec;
		scanf("%d", &dec);
		binary(dec);
		printf("\n");
		
	}

	return 0;
}
