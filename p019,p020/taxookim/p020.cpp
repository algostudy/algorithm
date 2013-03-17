#include <stdio.h>



//(24 + (-1 + n) n (18 + (-5 + n) n))/24
unsigned long long count(unsigned long long n){
	return 1 + ((n-1) * n * (18 + (n-5) * n))/24;
}

int main(void){
	unsigned long long result;
	int n;
	scanf("%d",&n);
	printf("%llu \n",count((unsigned long long)n));
	return 0;
}
