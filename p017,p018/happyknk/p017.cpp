#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char grid[50][51];
char word[20][51];

int main(){

	int count = 0;

	scanf("%d", &count);

	while(count-->0){
		int m, n, k;
		scanf("%d %d", &m, &n);
		for(int i=0; i<m; i++){
			scanf("%s", grid[k]);
		}

		scanf("%d", &k);
		for(int i=0; i<k; i++){
			scanf("%s", word[i]);
			int len = strlen(word[i]);

			for(int a=0; a<m; a++){
				for(int b=0; b<n; b++){
					if(){}

				}
			}




		}

	}

	printf("%d\n", x);

	return 0;
}
