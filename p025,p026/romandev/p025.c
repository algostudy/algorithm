#include <stdio.h>
#include <string.h>

inline static int
process(char* a_x, int a_x_len, char* a_z, int a_z_len)
{
	static int table[10002][10002];

	for ( int xi = 0; xi <= a_x_len; xi++ )
		table[0][xi] = 1;

	for ( int zi = 1; zi <= a_z_len; zi++ )
		for ( int xi = 1; xi <= a_x_len; xi++ )
			if ( a_x[xi - 1] == a_z[zi - 1] )
				table[zi][xi] = table[zi - 1][xi - 1] + table[zi][xi - 1];
			else
				table[zi][xi] = table[zi][xi - 1];

	return table[a_z_len][a_x_len];
}

int main(void)
{
	int n;
	char x[10001];
	char z[101];

	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
	{
		scanf("%s %s", x, z);
		printf("%d\n", process(x, strlen(x), z, strlen(z)));
	}
}
