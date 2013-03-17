#include <stdio.h>

inline static unsigned int
is_palindrome(unsigned int a_number, unsigned int* a_reverse_number)
{
	char         data[10];
	unsigned int length = 0;
	unsigned int half_length;
	unsigned int number = a_number;

	*a_reverse_number = 0;

	while ( number > 0 )
	{
		*a_reverse_number *= 10;
		data[length] = number % 10;
		*a_reverse_number += data[length];
		number /= 10;
		length++;
	}

	half_length = length >> 1;
	for ( int i = 0; i < half_length; i++ )
		if ( data[i] != data[length - i - 1] )
			return 0;

	return 1;
}

inline static void
print_palindrome(int a_number)
{
	unsigned int number = a_number;
	unsigned int count = 0;
	unsigned int reverse_number;

	while ( !is_palindrome(number, &reverse_number) )
	{
		number = number + reverse_number;
		count++;
	}

	printf("%u %u\n", count, number);
}

int main(void)
{
	unsigned int n;
	unsigned int number;

	scanf("%u", &n);

	for ( int i = 0; i < n; i++ )
	{
		scanf("%u", &number);
		print_palindrome(number);
	}

	return 0;
}
