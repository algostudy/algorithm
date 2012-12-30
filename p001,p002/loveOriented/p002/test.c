#include <stdio.h>

#define ABS(int) (int < 0) ? (int * (-1)) : (int)

int main()
{

	printf("%d %d\n", ABS(-1), ABS(1));
}

