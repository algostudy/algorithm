#include <stdio.h>
#include <math.h>

#define MAXN 1000

double expense[MAXN]; 

int main(void)
{
	int n;

	while ( 1 )
	{
		int n;
		double sum = 0;

		scanf("%d", &n);
		if ( n == 0 ) {
			break;
		}
	
		for ( int i = 0; i < n; i++ ) {
			scanf("%lf", &expense[i]);
			sum += expense[i];
		}
	
		double average = sum / n;
		double result = 0;
		for ( int i = 0; i < n; i++ ) {
			int difference = (expense[i] - average) * 100;
			int first = difference % 10;

			printf("diff = %d, first = %d\n", difference, first);

			if ( first == -1 ) {
				difference += 1;
			}
			printf("after diff = %d\n", difference);

			if ( difference < 1 ) {
				result +=difference;
//				result += difference;
			}
		}
		
		printf("$%.2lf\n", result / -100);
	}

		
	return 0;
}
