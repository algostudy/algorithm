#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE	3000
#define TRUE		1
#define	FALSE		0

int main(void)
{
	int n;
	int a, b;
	int diff;
	int table[MAX_VALUE] = { 0, };
	int count = 0;
	int is_jolly;
	const char* result[] = { "Not Jolly", "Jolly" };

	while ( scanf("%d", &n) == 1 )
	{
		is_jolly = TRUE;
		count--;

		scanf("%d", &a);
		for ( int i = 1; i < n; i++ )
		{
			scanf("%d", &b);
			if ( is_jolly )
			{
				diff = a > b ? a - b : b - a;

				if ( diff > n - 1 || table[diff - 1] == count )
					is_jolly = FALSE;
				else
					table[diff - 1] = count;

				a = b;
			}
		}

		printf("%s\n", result[is_jolly]);
	}

	return 0;
}
