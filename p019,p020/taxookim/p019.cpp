#include <stdio.h>

int check(long num){
	int a, b=0, i=10;
	a = num;
	
	while(a > b){
		b = (a%10) + (b*10);
		a = num / i;
		i = i*10;
	//	printf("%d , %d\n", a,b);
	}
	if((a == b) || ((b/10) == a))
		return 1;
	else
		return 0;
}

int main(void){
	int num = 109901;
	int result = 0;
	result = check(num);
	printf("%d", result);
	return 0;
}
