#include <stdio.h>

void IntToBin(int num) {
	if (num == 0) {
		printf("0");
		return;
	} else if (num == 1) {
		printf("1");
		return;
	} else {
		IntToBin(num>>1);
		printf("%d", (num&0x01));
		return;
	}
}

int main (void) {
	int testNum, input;
	scanf("%d", &testNum);
	for(int i=0 ; i<testNum ; i++) {
		scanf("%d", &input);
		IntToBin(input);
		printf("\n");
	}
	return 0;
}
