#include <stdio.h>

int main(void)
{
	int  offset[8][2] = {
		{ -1, -1 },
		{ -1, 0 },
		{ -1, 1 },
		{ 0, 1 },
		{ 1, 1 },
		{ 1, 0 },
		{ 1, -1 },
		{ 0, -1 }
	};
	char map[101][101];
	int  n, m;
	int  count = 1;

	while ( scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0) )
	{
		for ( int i = 0; i < n; i++ )
			scanf("%s", map[i]);

		for ( int y = 0; y < n; y++ )
			for ( int x = 0; x < m; x++ )
				if ( map[y][x] == '*' )
					for ( int i = 0; i < 8; i++ )
					{
						int offset_y = y + offset[i][0];
						int offset_x = x + offset[i][1];

						if ( map[offset_y][offset_x] != '*' && 
							0 <= offset_x && offset_x < m &&
							0 <= offset_y && offset_y < n )
							map[offset_y][offset_x]++;
					}
				else
					map[y][x] = map[y][x] - '.' + '0';

		printf("Field #%d:\n", count++);
		for ( int i = 0; i < n; i++ )
			printf("%s\n", map[i]);
		printf("\n");
	}

	return 0;
}
