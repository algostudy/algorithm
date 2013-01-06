#include <stdio.h>

#define LINE_MAX	2048

static char
wertyu_to_qwerty(char a_ch)
{
	static char mapping[] = "9`12345678AVXSWDFGUHJKNBIOQEARYCQZTZ0-P[LM,.;]";

	switch ( a_ch )
	{
	case '-':  a_ch = mapping[36]; break;
	case '=':  a_ch = mapping[37]; break;
	case '[':  a_ch = mapping[38]; break;
	case ']':  a_ch = mapping[39]; break;
	case ';':  a_ch = mapping[40]; break;
	case ',':  a_ch = mapping[41]; break;
	case '.':  a_ch = mapping[42]; break;
	case '/':  a_ch = mapping[43]; break;
	case '\'': a_ch = mapping[44]; break;
	case '\\': a_ch = mapping[45]; break;
	default:
		if ( 'A' <= a_ch && a_ch <= 'Z' )
			a_ch = mapping[a_ch - 'A' + 10];
		else if ( '0' <= a_ch && a_ch <= '9' )
			a_ch = mapping[a_ch - '0'];
	}

	return a_ch;
}

int main(void)
{
	char buffer[LINE_MAX];

	while ( fgets(buffer, LINE_MAX, stdin) != NULL )
	{
		char* position = buffer;

		while ( *position )
		{
			*position = wertyu_to_qwerty(*position);
			position++;
		}

		printf("%s", buffer);
	}

	return 0;
}
