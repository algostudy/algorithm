#include <stdio.h>



void hanoi(int num, int start, int dest, int empty)
{
	if(num > 0)
	{
		hanoi(num - 1, start, empty, dest);
		printf("%d->%d\n", start, dest);
		hanoi(num - 1, empty,dest, start);
	}
	
}

int main(void)
{
	int num;
	while(scanf("%d", &num) == 1)
	{
		hanoi(num, 1,3,2);
		printf("\n");
	}
	return 0;
}
