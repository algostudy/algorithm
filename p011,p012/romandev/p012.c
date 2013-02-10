#include <stdio.h>
#include <math.h>

int main(void)
{
	unsigned int n;
	double		 sqrt_n;
	unsigned int sqrt_int_n;
	unsigned int step;
	unsigned int lower_bound, upper_bound, middle_point;
	unsigned int coordinate[2];

	while ( scanf("%u", &n) == 1 && n != 0 )
	{
		sqrt_n = sqrt(n);
		sqrt_int_n = (unsigned int)sqrt_n;

		if ( sqrt_n == sqrt_int_n )
		{
			coordinate[sqrt_int_n & 1] = sqrt_int_n;
			coordinate[(sqrt_int_n + 1) & 1] = 1;
		}
		else
		{
			step = sqrt_int_n + 1;
			lower_bound = sqrt_int_n * sqrt_int_n;
			upper_bound = step * step + 1;
			middle_point = lower_bound + step;

			if ( n > middle_point )
			{
				coordinate[step & 1] = step;
				coordinate[(step + 1) & 1] = upper_bound - n;
			}
			else if ( n < middle_point )
			{
				coordinate[step & 1] = n - lower_bound;
				coordinate[(step + 1) & 1] = step;
			}
			else	// n == middle_point
			{
				coordinate[0] = coordinate[1] = step;
			}
		}

		printf("%u %u\n", coordinate[0], coordinate[1]);
	}

	return 0;
}
