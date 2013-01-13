#include <stdio.h>
#include <string.h>

static char fib_buffer[500][200] = { "0", "1", "2", };
static char* fib[500] = { "0", "1", "2", };

static char*
big_int_add(char* a_x, char* a_y, char* a_result)
{
	int   x_length = strlen(a_x);
	int   y_length = strlen(a_y);
	int   bigger_index;
	int   smaller_index;
	char* bigger;
	char* smaller;

	int   carry = 0;
	int   remain;
	int   sum;

	if ( x_length >= y_length )
	{
		bigger_index = x_length;
		smaller_index = y_length;
		bigger = a_x;
		smaller = a_y;
	}
	else
	{
		bigger_index = y_length;
		smaller_index = x_length;
		bigger = a_y;
		smaller = a_x;
	}

	while ( --bigger_index >= 0 && --smaller_index >= 0 )
	{
		sum = (bigger[bigger_index] - '0') + (smaller[smaller_index] - '0') + carry;
		carry = sum / 10;
		a_result[bigger_index + 1] = (sum % 10) + '0';
	}

	while ( bigger_index >= 0 )
	{
		sum = (bigger[bigger_index] - '0') + carry;
		carry = sum / 10;
		a_result[bigger_index + 1] = (sum % 10) + '0';
		bigger_index--;
	}

	a_result[0] = carry + '0';

	return a_result + (!carry);
}

inline static int
is_smaller(char* a_x, char* a_y)
{
	int x_length = strlen(a_x);
	int y_length = strlen(a_y);

	if ( x_length < y_length )
		return 1;
	else if ( x_length > y_length )
		return 0;

	for ( int i = 0; i < x_length; i++ )
	{
		if ( (a_x[i] - '0') < (a_y[i] - '0') )
			return 1;
		if ( (a_x[i] - '0') > (a_y[i] - '0') )
			return 0;
	}

	return 1;
}

static void
fill_fib()
{
	for ( int n = 3; n < 500; n++ )
		fib[n] = big_int_add(fib[n - 2], fib[n - 1], fib_buffer[n]);
}

static int
fib_count(char* a_a, char* a_b)
{
	int count = 0;

	for ( int n = 1; n < 500; n++ )
	{
		if ( is_smaller(a_a, fib[n]) && is_smaller(fib[n], a_b) )
			count++;
		else if ( is_smaller(a_b, fib[n]) )
			break;
	}

	return count;
}

int main(void)
{
	char a[200];
	char b[200];

	fill_fib();

	while ( scanf("%s %s", a, b) == 2 && (strcmp(a, "0") != 0 || strcmp(b, "0") != 0) )
		printf("%d\n", fib_count(a, b));

	return 0;
}
