#include <stdio.h>

void conv_dec_to_bin(int a_n)
{
	if ( a_n <= 0 )
	{
		printf("\n");
		return;
	}

	conv_dec_to_bin(a_n / 2);
	printf("%d", a_n % 2);
}

int main(void)
{
	int test_case_count;
	int n;

	scanf("%d", &test_case_count);
	for ( int i = 0; i < test_case_count; i++ )
	{
		scanf("%d", &n);
		conv_dec_to_bin(n);
	}

	return 0;
}
