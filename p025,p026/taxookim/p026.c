#include <stdio.h>

#define MAX_CASE 100
#define MAGIC_NUMBER 1000000007

unsigned long long fibo[MAX_CASE+1];

void MakeFibo(void);

int main(void){
	int numTestcase;
	MakeFibo();
	scanf("%d", &numTestcase);
	
	for(int i=0 ; i<numTestcase ; i++){
		int input;
		unsigned long long result;
		scanf("%d", &input);

		if(input < 3) {
			printf("0\n");
		} else {
			if(input & 0x1) {
				result = fibo[input] + MAGIC_NUMBER - fibo[input>>1];
			} else {
				result = fibo[input] + MAGIC_NUMBER - fibo[input>>1] + MAGIC_NUMBER - fibo[(input-2)>>1];
			}
			result %= MAGIC_NUMBER;
			printf("%ld\n", result);
		}
	}
}

void MakeFibo(void){
	int i = 1;
	fibo[i++] = 1;
	fibo[i++] = 2;
	for( ; i<MAX_CASE+1 ; i++){
		fibo[i] = (fibo[i-1] + fibo[i-2]) % MAGIC_NUMBER;
	}
	return;
}
