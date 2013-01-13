#include <stdio.h>
#include <stdlib.h>

int main(){

	while(1){
		long long n1=0;
		long long n2=0;
		int carry = 0;
		int count = 0;
		scanf("%ld %ld", &n1, &n2);
		if(n1==0 && n2==0) break;

		while(1){
			if(n1==0 && n2==0) break;
			carry = ( ( n1%10 + n2%10 + carry ) > 9 )?1:0;
			count += carry;
			n1 /= 10;
			n2 /= 10;
		}
		printf("%d\n", count);
	}
	return 0;
}

