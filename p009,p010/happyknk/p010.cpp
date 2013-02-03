#include <stdio.h>
#include <stdlib.h>


int main(){

	int n;

	scanf("%d", &n);
	while(n>0){
		int k;
		scanf("%d", &k);

		while(k>0){
			double x, y;
			scanf("%lf %lf", &x, &y);

			k--;
		}


		n--;
	}




//printf("%d\n", count);
	return 0;
}

