#include <stdio.h>


char keyPattern[128] = {0};

void
makeArray()
{

	keyPattern['1'] = '`';
	keyPattern['2'] = '1';
	keyPattern['3'] = '2';
	keyPattern['4'] = '3';
	keyPattern['5'] = '4';
	keyPattern['6'] = '5';
	keyPattern['7'] = '6';
	keyPattern['8'] = '7';
	keyPattern['9'] = '8';
	keyPattern['0'] = '9';
	keyPattern['-'] = '0';
	keyPattern['='] = '-';
	keyPattern[' '] = ' ';

	keyPattern['W'] = 'Q';
	keyPattern['E'] = 'W';
	keyPattern['R'] = 'E';
	keyPattern['T'] = 'R';
	keyPattern['Y'] = 'T';
	keyPattern['U'] = 'Y';
	keyPattern['I'] = 'U';
	keyPattern['O'] = 'I';
	keyPattern['P'] = 'O';

	keyPattern['S'] = 'A';
	keyPattern['D'] = 'S';
	keyPattern['F'] = 'D';
	keyPattern['G'] = 'F';
	keyPattern['H'] = 'G';
	keyPattern['J'] = 'H';
	keyPattern['K'] = 'J';
	keyPattern['L'] = 'K';
	keyPattern[';'] = 'L';

	keyPattern['X'] = 'Z';
	keyPattern['C'] = 'X';
	keyPattern['V'] = 'C';
	keyPattern['B'] = 'V';
	keyPattern['N'] = 'B';
	keyPattern['M'] = 'N';
	keyPattern[','] = 'M';
#if 0
	keyPattern['w'] = 'q';
	keyPattern['e'] = 'w';
	keyPattern['r'] = 'e';
	keyPattern['t'] = 'r';
	keyPattern['y'] = 't';
	keyPattern['u'] = 'y';
	keyPattern['i'] = 'u';
	keyPattern['o'] = 'i';
	keyPattern['p'] = 'o';
#endif
	keyPattern['['] = 'P';
	keyPattern[']'] = '[';
	keyPattern[']'] = '[';
	keyPattern['\\'] = ']';

#if 0
	keyPattern['s'] = 'a';
	keyPattern['d'] = 's';
	keyPattern['f'] = 'd';
	keyPattern['g'] = 'f';
	keyPattern['h'] = 'g';
	keyPattern['j'] = 'h';
	keyPattern['k'] = 'j';
	keyPattern['l'] = 'k';
	keyPattern[';'] = 'l';
#endif
	keyPattern['\''] = ';';
#if 0
	keyPattern['x'] = 'z';
	keyPattern['c'] = 'x';
	keyPattern['v'] = 'c';
	keyPattern['b'] = 'v';
	keyPattern['n'] = 'b';
	keyPattern['m'] = 'n';
	keyPattern[','] = 'm';
#endif
	keyPattern['.'] = ',';
	keyPattern['/'] = '.';

	keyPattern[10] = 10;
	keyPattern[13] = 13;
	return;
}


int
main()
{
	char c;
	makeArray();

	while( scanf("%c", &c) == 1)
	{
		printf("%c",keyPattern[c]);		
	}

	return 0;
}
