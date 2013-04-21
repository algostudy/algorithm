#include <stdio.h>
#include <stdlib.h>

void hanoii(int n, int a, int b, int c){
	if( n == 1 ){ 
		printf("%d->%d\n", a, c);
	}else{
		hanoii(n-1, a, c, b);
		printf("%d->%d\n", a, c);
		hanoii(n-1, b, a, c);
	}
}

int main(){
	
	int count = 0;
	int n;

	while( count++ < 10 ){
		scanf("%d", &n);

		hanoii(n, 1, 2, 3);
		printf("\n");
		
	}

	return 0;
}
