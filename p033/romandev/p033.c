#include <stdio.h>

int main(void)
{
	int    n = 0;
	double sum;
	double sum2;
	double average;
	double students[1000];

	while ( scanf("%d", &n) == 1 && n != 0 )
	{
		sum = 0.0;

		for ( int si = 0; si < n; si++ )
		{
			scanf("%lf", &students[si]);
			sum += students[si];
		}

		average = ((int)((sum / n) * 100 + 0.5)) / 100.0;

		sum = 0.0;
		sum2 = 0.0;
		for ( int si = 0; si < n; si++ )
		{
			if ( students[si] < average )
				sum += average - students[si];
			else
				sum2 += students[si] - average;
		}

		printf("$%.2lf\n", (sum < sum2 ? sum : sum2));
	}

	return 0;
}
