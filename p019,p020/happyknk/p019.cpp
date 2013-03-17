#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int reverse(unsigned int a){

	unsigned int temp[20];
	int len = 0;
	unsigned int result = 0;
	unsigned int d = 1;

	while(a>0){
		temp[len++] = a%10;
		a = a/10;
	}

	/*for(int j=0; j<len; j++){
		printf("%d", temp[j]);
	}*/

	for(int i=len-1; i>=0; i--){
		result += temp[i] * d;
		d*=10;
	}
	//printf("result - %u \n", result);

	return result;

}

int main(){

	int n = 0;
	int count = 0;

	scanf("%d", &n);

	while(count++<n){
		unsigned int input;
		unsigned int rev;
		int cnt = 0;

		scanf("%d", &input);
		
		while(input){
			rev = reverse(input);

		//	printf("%d-", cnt);
		//	printf("result - %u %u\n", rev, input+rev);
			if(input == rev){
				break;
			}else{
				input = input + rev;
			}
			cnt++;
		}
		printf("%d %u\n", cnt, input);

	}


	return 0;
}

