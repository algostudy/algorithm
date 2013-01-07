#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int   test_cases;
        int   r;
	int   s[500];
        int   vito;
 
        scanf("%d", &test_cases);
        for ( int i = 0; i < test_cases; i++ )
	{
		char list[30001] = { 0, };
		int  count = 0;
		int  mid;
		int  sum = 0;

                scanf("%d", &r);

		mid = r / 2;
                for ( int j = 0; j < r; j++ )
		{
                        scanf("%d", s + j);
			list[s[j]]++;
		}

		for ( int j = 0; j < 30000; j++ )
		{
			count += list[j];

			if ( count > mid )
			{
				vito = j;
				break;
			}
		}

		for ( int j = 0; j < r; j++ )
			sum += (vito > s[j] ? vito - s[j] : s[j] - vito);

		printf("%d\n", sum);
	}

	return 0;
}
