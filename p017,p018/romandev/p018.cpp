#include <iostream>
#include <string>
#include <sstream>

using namespace std;

inline static void
flip(int* a_stack, int a_length, int a_position)
{
	int left = a_position - 1;
	int right = a_length - 1;

	while ( left < right )
	{
		a_stack[left] ^= a_stack[right];
		a_stack[right] ^= a_stack[left];
		a_stack[left] ^= a_stack[right];
		left++;
		right--;
	}
}

inline static int
get_max(int* a_stack, int a_start, int a_end)
{
	int max = -1;
	int max_index = -1;

	for ( int i = a_start; i < a_end; i++ )
		if ( max < a_stack[i] )
		{
			max = a_stack[i];
			max_index = i;
		}

	return max_index + 1;
}

int main(void)
{
	string data;
	int    count;
	int    stack_internal[30];
	int*   stack;

	while ( getline(cin, data) )
	{
		istringstream data_stream(data);
		count = 0;

		while ( data_stream >> stack_internal[29 - count] )
		{
			cout << stack_internal[29 - count] << " ";
			count++;
		}

		stack = stack_internal + 30 - count;

		cout << endl;
		for ( int i = 1; i < count; i++ )
		{
			int max_index = get_max(stack, i - 1, count);

			if ( max_index == i )
			{
				continue;
			}
			else if ( max_index == count )
			{
				flip(stack, count, i);
				cout << i << " ";
			}
			else
			{
				flip(stack, count, max_index);
				flip(stack, count, i);
				cout << max_index << " " << i << " ";
			}
		}
		cout << "0" << endl;
	}

	return 0;
}
