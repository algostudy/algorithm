#include <stdio.h>

void hanoi(int a_from, int a_tmp, int a_to, int a_n)
{
	if ( a_n == 0 )
		return;

	hanoi(a_from, a_to, a_tmp, a_n - 1);
	printf("%d->%d\n", a_from, a_to);
	hanoi(a_tmp, a_from, a_to, a_n - 1);
}

int main(void)
{
	int n;

	while ( scanf("%d", &n) == 1 )
	{
		hanoi(1, 2, 3, n);
		printf("\n");
	}

	return 0;
}
