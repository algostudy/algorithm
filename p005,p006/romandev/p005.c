#include <stdio.h>

int main(void)
{
	long x, y;
	long carry;

	while ( scanf("%ld %ld", &x, &y) == 2 && (x != 0 && y != 0) )
	{
		carry = 0;

		while ( x + y )
		{
			carry += (x % 10 + y % 10) >= 10 ? 1 : 0;
			x /= 10;
			y /= 10;
		}

		printf("%d\n", carry);
	}

	return 0;
}
