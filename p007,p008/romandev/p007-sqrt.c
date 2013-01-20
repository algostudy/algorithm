#include <stdio.h>
#include <math.h>

int main(void)
{
	double n;
	double sqrt_n;
	unsigned int uint_sqrt_n;

	while ( scanf("%lf", &n) && n )
	{
		sqrt_n = sqrt(n);
		uint_sqrt_n = sqrt_n;

		if ( sqrt_n - uint_sqrt_n == 0.0 )
		//if ( uint_sqrt_n * uint_sqrt_n == n )
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
