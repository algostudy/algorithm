#include <stdio.h>

int g_table[3651];
int g_key = 1;

int main(void)
{
	int t, n, p, h;
	int count;
	int day;

	scanf("%d", &t);
	for ( int ti = 0; ti < t; ti++ )
	{
		count = 0;
		scanf("%d %d", &n, &p);
		for ( int pi = 0; pi < p; pi++ )
		{
			scanf("%d", &h);
			for ( int hi = h; hi <= n; hi += h )
			{
				day = hi % 7;

				if ( day != 0 && day != 6 && g_table[hi] != g_key )
				{
					g_table[hi] = g_key;
					count++;
				}
			}
		}

		g_key++;
		printf("%d\n", count);
	}
}
