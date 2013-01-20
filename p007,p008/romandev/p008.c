#include <stdio.h>

static int
put_bishop(char (*a_table)[8], int a_n, int a_x, int a_y)
{
	int steps[][2] = {
		{ -1, -1 }, // left  up
		{ +1, -1 }, // right up
		{ -1, +1 }, // left  down
		{ +1, +1 }  // right down
	};

	for ( int i = 0; i < 4; i++ )
	{
		for ( int x = a_x + steps[i][0], y = a_y + steps[i][1];
		      0 <= x && x < a_n && 0 <= y && y < a_n;
		      x += steps[i][0], y += steps[i][1] )
		{
			if ( a_table[y][x] == '*' )
				return 0;
		}
	}

	a_table[a_y][a_x] = '*';

	return 1;
}

static int
search_ways(int a_n, int a_k)
{
	int max = a_n * a_n;
	int depth = a_k;
	int index = depth - 1;
	int count = 0;

	int stack[1024];
	int stack_index = 0;

	while ( index < max )
	{
		if ( depth > 1 )	/* external loops */
		{
			stack[stack_index++] = index;
			stack[stack_index++] = max;
			stack[stack_index++] = depth;

			/* set new loop */
			depth--;
			max = index;
			index = depth - 1;
	
			continue;
		}
		else			/* internal loop */
		{
			char table[8][8] = { 0, };
			int  x, y;

			for ( int i = 0; i < stack_index; i += 3 )
			{
				x = stack[i] % a_n;
				y = stack[i] / a_n;

				if ( put_bishop(table, a_n, x, y) == 0 )
					goto no_count;
			}

			x = index % a_n;
			y = index / a_n;

			if ( put_bishop(table, a_n, x, y) == 0 )
				goto no_count;

			count++;

			no_count:;
		}

		index++;

		while ( index == max && stack_index != 0 )
		{
			depth = stack[--stack_index];
			max = stack[--stack_index];
			index = stack[--stack_index] + 1;
		}
	}

	return count;
}

int main(void)
{
	int n, k;

	while ( scanf("%d %d", &n, &k) == 2 && (n != 0 || k != 0) )
	{
		if ( n < 1 || n > 8 || k < 0 || k > n * n )
		{
			printf("input error\n");
			break;
		}

		printf("%d\n", search_ways(n, k));
		fflush(stdout);
	}

	return 0;
}
