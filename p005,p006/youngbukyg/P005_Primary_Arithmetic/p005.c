#include <stdio.h>

int main(void)
{
	int x;
	int y;

	while ( scanf("%d %d", &x, &y) == 2 )
	{
		printf("%d %d\n", x, y);
	}
	
	return 0;
}
