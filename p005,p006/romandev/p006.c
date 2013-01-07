#include <stdio.h>
#include <string.h>

static char*
big_int_add(char* a_x, char* a_y, char* a_result)
{
	int x_length = strlen(a_x);
	int y_length = strlen(a_y);
	char* remain = x_length > y_length ? a_x : a_y;
	int index = x_length > y_length ? x_length : y_length;
	int carry = 0;

	while ( !(--x_length < 0 || --y_length < 0) )
	{
		int x = a_x[x_length] - '0';
		int y = a_y[y_length] - '0';
		int sum = x + y + carry;
		a_result[index--] = (sum % 10) + '0';
		carry = sum / 10;
	}

	while ( index )
	{
		int sum = remain[index - 1] - '0' + carry;
		a_result[index] = (sum % 10) + '0';
		carry = sum / 10;
		index--;
	}

	a_result[index] = carry + '0';

	return carry > 0 ? a_result : a_result + 1;
}

static char*
fibonacci(char* a_n)
{
	char* n2 = "1";
	char* n1 = "2";
	char n[1024];
	char* result;

	do
	{
		result = big_int_add(n2, n1, n);
		n2 = n1;
		n1 = result;
	} while ( strcmp(a_n, result) )
}

// 1 2 3 5 8
static int
fib(int a_n)
{
	if ( a_n <= 2 )
		return a_n;
	else
		return fib(a_n - 2) + fib(a_n - 1);
}

int main(void)
{

	printf("%d", fib(5));
/*	char buffer[1024] = { 0, };
	char* result;

	result = big_int_add("1873", "123", buffer);

	printf("%s", result);
*/
	return 0;
}
