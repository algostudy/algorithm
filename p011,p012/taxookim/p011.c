#include <stdio.h>

void result(int);

int main(void) {
	int input;
	while(scanf("%d",&input)){
		if(input == 0) return 0;
		result(input);
	}
	return 0;
}

void result(int in){
	int mTwo=0, mThree=0, mFive=0;
	if(in == 2){
		mTwo = 1;
	}else if(in == 3){
		mThree = 1;
	}else{
		if((in % 2) == 0) {
			mTwo = in / 2;
		}else{
			mTwo = (in / 2) - 1;
		}
		if((in % 3) != 1){
			mThree = in / 3;
		}else{
			mThree = (in / 3) - 1;
		}
		if((in % 5) != 1){
			mFive = in / 5;
		}else{
			mFive = (in / 5) - 1;
		}
	}
	printf("2: %d, 3: %d, 5: %d\n", mTwo, mThree, mFive);
}

