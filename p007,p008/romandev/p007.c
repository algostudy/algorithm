#include <stdio.h>
#include <math.h>

typedef unsigned int uint32;

static uint32 prime[10000];

inline static uint32
is_prime_number(uint32 a_number)
{
	if ( a_number > 2 && a_number % 2 == 0 )
		return 0;

	for ( uint32 i = 3; i < sqrt(a_number) + 1; i += 2 )
		if ( a_number % i == 0 )
			return 0;

	return 1;
}

static uint32
set_prime_numbers(void)
{
	uint32 count = 0;

	//prime[count++] = 2;

	// sqrt(2^32 - 1) < 65536 (max)
	for ( int i = 3; i <= 65536; i+= 2 )
		if ( is_prime_number(i) )
			prime[count++] = i;

	// only end point. 65536 is not prime number
	prime[count] = 65536;

	return count;
}

int main(void)
{
	uint32 n;
	uint32 sqrt_n;
	uint32 num_of_factor = 1;
	uint32 count;
	char*  status[] = { "no", "yes" };

	set_prime_numbers();

	while ( scanf("%u", &n) == 1 && n != 0 )
	{
		sqrt_n = sqrt(n);
		num_of_factor = 1;

		count = 0;

		// 2 * 2 * 2 * ... * 2
		if ( 2 <= sqrt_n )
		{
			while ( n % 2 == 0 )
			{
				n = n >> 1;
				count++;
			}

			num_of_factor *= (count + 1);
		}

		// N * N * N * ... * N (N >= 3)
		uint32 i = 0;
		while ( prime[i] <= sqrt_n )
		{
			count = 0;
			while ( n % prime[i] == 0 )
			{
				n = n / prime[i];
				count++;
			}

			num_of_factor *= (count + 1);
			i++;
		}

		if ( n != 1 )
			printf("no\n");
		else
			printf("%s\n", status[num_of_factor % 2]);
	}

	return 0;
}
