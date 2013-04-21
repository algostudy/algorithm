#include <stdio.h>

int count;

void hanoi(int first, int second, int third, int num) {
	count++;
	if (num == 1) {
		printf("%d->%d\n", first, third);
	} else {
		hanoi(first, third, second, num-1);
		printf("%d->%d\n", first, third);
		hanoi(second, first, third, num-1);
	}
}

int main(void){
	int input;
	while((scanf("%d", &input))==1) {
		hanoi(1, 2, 3, input);
		printf("\n");
	}
	return 0;
}
