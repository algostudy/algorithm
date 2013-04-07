#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0;

	scanf("%d", &n);

	while(n-- > 0){
		char a[10000];
		char b[100];
		int idx[100];
		int count = 0;

		scanf("%s", a);
		scanf("%s", b);

		int i = 0;
		int j = 0;

		for(j=0; j<strlen(b); j++){
			for(i=0; i<strlen(a); i++){
				if(a[i]==b[j]){
					idx[j] == i;
					break;
				}
			}
		}

		if(idx[--j]!=0){
			count++;

		}

		


		printf("%d\n", a);




	}

	return 0;
}
