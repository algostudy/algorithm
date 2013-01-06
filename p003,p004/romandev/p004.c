#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#define debug(a_arg, ...) { \
	printf("[%10s():%d] " a_arg "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); \
	fflush(stdout); \
	}

#ifndef DEBUG
#define debug
#endif

void quick_sort(int a_data[], int a_length)
{
	int left = 0;
	int right = a_length;
	int pivot = a_data[0];

	if ( a_length > 1 )
	{
		while ( 1 )
		{
			while ( a_data[++left] < pivot ) ;
			while ( a_data[--right] > pivot ) ;

			if ( left >= right ) break;

			a_data[left] ^= a_data[right];
			a_data[right] ^= a_data[left];
			a_data[left] ^= a_data[right];
		}

		a_data[0] = a_data[right];
		a_data[right] = pivot;

		quick_sort(a_data, right);
		quick_sort(a_data + right + 1, a_length - right - 1);
	}
}

int main(void)
{
	int   test_cases;
        int   r;
        int   s[500];
        int   vito;
	int   sum;
 
        scanf("%d", &test_cases);
        for ( int i = 0; i < test_cases; i++ )
	{                       
                scanf("%d", &r);
                for ( int j = 0; j < r; j++ )
                        scanf("%d", s + j);

		quick_sort(s, r);

		vito = s[r / 2];
		sum = 0;

		for ( int j = 0; j < r; j++ )
			sum += (vito > s[j] ? vito - s[j] : s[j] - vito);

		printf("%d\n", sum);
		fflush(stdout);
	}

	return 0;
}
