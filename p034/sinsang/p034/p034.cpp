#include <stdio.h>
#include <string.h>

#define MAXN 1000

int main(void)
{
	int i, j, targetn;
	int an, bn;

	char a[MAXN + 1];
	char b[MAXN + 2];
	int result[2][26];

	while ( 1 )
	{
		if ( scanf("%s", a) != 1 ) {
			return 1;
		}

		scanf("%s", b);

		an = strlen(a);
		bn = strlen(b);

		for ( i = 0; i < 26; i++ ) {
			result[0][i] = 0;
			result[1][i] = 0;
		}

		for ( i = 0; i < an; i++ ) {
			result[0][a[i]-'a']++;
		}
		
		for ( i = 0; i < bn; i++ ) {
			result[1][b[i]-'a']++;
		}

		for ( i = 0; i < 26; i++ ) {			
			if ( result[0][i] >= 1 && result[1][i] >= 1 ) {
				if ( result[0][i] > result[1][i] ) {
					targetn = result[1][i];
				}
				else {
					targetn = result[0][i];
				}
				
				for ( j = 0; j < targetn; j++ ) {
					printf("%c", 'a' + i);
				}
			}
		}
		printf("\n");
	}
}
