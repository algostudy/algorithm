#include <stdio.h>

unsigned int g_tiling[101] = { 0, 1, 2 };
unsigned int g_asym_tiling[101] = { 0, };

int main(void)
{
	unsigned int c, n;

	for ( int i = 3; i <= 100; i++ )
	{
		g_tiling[i] = (g_tiling[i - 1] + g_tiling[i - 2]) % 1000000007;
		g_asym_tiling[i] = (g_tiling[i] - g_tiling[i / 2 + !(i & 1)] + 1000000007) % 1000000007;
	}

	scanf("%u", &c);
	for ( int i = 0; i < c; i++ )
	{
		scanf("%u", &n);
		printf("%u\n", g_asym_tiling[n]);
	}

	return 0;
}
