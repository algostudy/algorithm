#include <stdio.h>
#include <limits.h>

#define	MAX_VALUE	1000000

typedef unsigned int uint32;

inline static uint32
get_cycle_length(uint32 a_n)
{
	static uint32 cache[MAX_VALUE] = { 0, };

	uint32 n = a_n;
	uint32 length = 1;

	if ( cache[n] != 0 )
		return cache[n];

	while ( n != 1 )
	{
		if ( n & 1 )		// odd
			n = n * 3 + 1;
		else			// even
			n >>= 1;	// n = n / 2

		length++;
	}

	cache[a_n] = length;

	return length;
}

int main(void)
{
	uint32 i, j;

	while ( scanf("%u %u", &i, &j) == 2 )
	{
		uint32 max_length = 0;

		for ( uint32 k = i; k <= j; k++ )
		{
			uint32 length = get_cycle_length(k);

			if ( max_length < length )
				max_length = length;
		}

		printf("%u %u %u\n", i, j, max_length);
	}

	return 0;
}
