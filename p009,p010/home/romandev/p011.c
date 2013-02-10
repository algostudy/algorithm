#include <stdio.h>

inline static unsigned long
get_num_of_ways(unsigned long a_n)
{
	static unsigned long way[101] = { 0, 0, 1, 1, 1, 3 };

	if ( way[a_n] == 0 && a_n > 5 )
		way[a_n] = get_num_of_ways(a_n - 2) +
			get_num_of_ways(a_n - 3) +
			get_num_of_ways(a_n - 5);	

	return way[a_n];
}

int main(void)
{
	unsigned long n;

	while ( scanf("%lu", &n) == 1 && n != 0 )
		printf("%lu\n", get_num_of_ways(n));

	return 0;
}
