#include <stdio.h>
#include <stdlib.h>

char field[101][101];

int main(){
	
	int count = 1;
	int m = 0, n = 0;

	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0 || m == 0 ) break;
		for(int i=0; i<n; i++){
			getchar();
			int j=0;
			for(; j<m; j++){
				field[i][j] = getchar();
			}
		}

		printf("Field #%d:\n", count++);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(field[i][j]=='.'){
					int mine = 0;
					if( (i>0 && j>0) && field[i-1][j-1]=='*' ){
						mine++;
					}
					if( (i+1<n && j+1<m) && field[i+1][j+1]=='*' ){
						mine++;
					}
					if( (i>0 && j+1<m) && field[i-1][j+1]=='*' ){
						mine++;
					}
					if( (i+1<n && j>0) && field[i+1][j-1]=='*' ){
						mine++;
					}
					if( i>0 && field[i-1][j]=='*' ){
						mine++;
					}
					if( i+1<n && field[i+1][j]=='*' ){
						mine++;
					}
					if( j>0 && field[i][j-1]=='*' ){
						mine++;
					}
					if( j+1<m && field[i][j+1]=='*' ){
						mine++;
					}

					field[i][j] = mine;
					printf("%d", field[i][j]);
				}else{
					printf("*");
				}
			}
			printf("\n");
		}
	}


//	printf("%d\n", x);

	return 0;
}
