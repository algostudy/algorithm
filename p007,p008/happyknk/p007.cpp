#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kyungSqrt(long long n){
	long long odd = 1;
	int count = 1;
	while((n-=odd)!=0){
		count++;
		odd+=2;
	}
	return count;
}

int main(){

	long long n = 0;

	while(scanf("%ld", &n)){

		if(n==0) break;
		int count = 0;
		int sq = kyungSqrt(n);
		for(long long i=1; i<=sq; i++){
			if(n%i==0) count++;
		}
		count*=2;
		if(sq*sq == n) count-=1;

		if(count%2==1)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
