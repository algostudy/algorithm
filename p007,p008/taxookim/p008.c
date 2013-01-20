#include <stdio.h>

#define DEBUG(n)	printf(" %d.",(n))
#define BOARD_SIZE	8

int board[BOARD_SIZE][BOARD_SIZE] = {0,};

void init(int size);
int countPosition(int size, int bishop);

int main(void){
	int result=0;
	int size, bishop;

	while(1){
		scanf("%d %d", &size, &bishop);
		if((size==0) || (bishop==0)) break;
		init(size);
		result = countPosition(size, bishop);
		printf("%d\n", result);
	}
	return 0;
}

void init(int size){
	int i, j=0;
	for(i=0 ; i<BOARD_SIZE ; i++)
		for(j=0 ; j<BOARD_SIZE ; j++)
			if((i<size)&&(j<size) 	board[i][j] = 0;
			else			board[i][j] = 99;
	return;
}

int countPosition(int size, int bishop){

}

int checkPosition(int x, int y){
	int i,j;
	for(i=0 ; board[i][0] < 99 ; i++)
		for(j=0 ; board[0][j] < 99 ; j++)
}
