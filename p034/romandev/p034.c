#include <stdio.h>

#define char_to_index(a_ch) (a_ch - 'a')
#define index_to_char(a_id) (a_id + 'a')

int unit_process(void)
{
	static char  input[1001];
	static char  status1[26];
	static char  status2[26];
	static char* position;

	for ( int si = 0; si < 26; si++ )
		status1[si] = status2[si] = 0;

	if ( scanf("%s\n", input) != 1 )
		return 0;
	position = input;

	while ( *position )
		status1[char_to_index(*position++)]++;

	if ( scanf("%s\n", input) != 1 )
		return 0;
	position = input;

	while ( *position )
	{
		int index = char_to_index(*position++);

		if ( status1[index] > 0 )
		{
			status1[index]--;
			status2[index]++;
		}
	}

	for ( int si = 0; si < 26; si++ )
		for ( int count = status2[si]; count > 0; count-- )
			printf("%c", index_to_char(si));
	printf("\n");

	return 1;
}

int main(void)
{
		while ( unit_process() )
				;

		return 0;
}
