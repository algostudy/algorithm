#include <stdio.h>
#include <math.h>

void printXY(int);

int main(void){
	int input;
	while(scanf("%d", &input)){
		if(input > 0){
			printXY(input);
		}else{
			return 0;
		}
	}
	return 0;
}

void printXY(int num){
	int level, x, y, edge, tmp, sqLevel;
	int isOdd = 0;

	level = sqrt(num);
	sqLevel = level * level;
	if(num > sqLevel){
		level++;

		x = level;
		edge = sqLevel + level;
		tmp = edge - num;
		y = (tmp>0)?(level-tmp):(level+tmp);
	}else{
		x = level;
		y = 1;
	}

	isOdd = level%2;
	if( ((isOdd!=1) && (num > edge)) || ((isOdd==1) && (num < edge)) ){
		printf("%d %d\n", x, y);
	}else{
		printf("%d %d\n", y, x);
	}
}
