#include <stdio.h>

int result[100][100];
char board[100][100];

void check(int, int);

int main(void){
	int inx, iny;
	int i,j;
	char bomb;
	int round = 0;
	while(scanf("%d %d", &iny, &inx) == 2){
		if(inx == iny == 0){
			return 0;
		}
		round++;
		for(i=0 ; i < iny ; i++){
			scanf("%s", board[i]);
		}
/*
		printf("%d %d\n", inx, iny);

		for(i=0 ; i < iny ; i++){
			for(j=0 ; j < inx ; j++){
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
*/

		printf("Field #%d:\n", round);
		check(iny, inx);
		printf("\n");
	}
	return 0;
}

void check(int y, int x){
	int i,j, k,l;
	int ty, tx;
	for(i=0 ; i<y ; i++)
		for(j=0 ; j<x ; j++){
			result[y][x] = 0;
		}
		
	for(i=0 ; i < y ; i++){
		for(j=0 ; j < x ; j++){
			if(board[y][x] == '*'){
				for(k=-1 ; k<2 ;k++){
				for(l=-1 ; l<2 ; l++){
					if((i+k>0) && (j+l>0) && (i+k<y) && (j+l<x)){
						if(board[i+k][j+l] != '*')
							result[i+k][j+l] += 1;
						else
							result[i+k][j+l] = '*';
					}
				}
				}
			}
		}
	}
	for(i=0 ; i<y ; i++){
		for(j=0 ; j<x ; j++){
			if(result[y][x] == '*')
				printf("*");
			else
				printf("%d", result[y][x]); 
		}
		printf("\n");
	}
}
