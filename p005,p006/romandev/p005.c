#include <stdio.h>
#include <string.h>

int main(void)
{
	long x, y;
	long carry;
	long count;

	while ( scanf("%ld %ld", &x, &y) == 2 && (x != 0 && y != 0) )
	{
		carry = 0;
		count = 0;

		while ( x + y )
		{
			carry = (x % 10 + y % 10 + carry) / 10;
			count += carry;
			x /= 10;
			y /= 10;
		}

		printf("%d\n", count);
	}

	return 0;
}
