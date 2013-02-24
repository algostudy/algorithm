#include <stdio.h>

typedef struct
{
	char value;
	char shape;
	unsigned char:8;
} card;

typedef struct
{
	card black[5];
	card white[5];
} card_game;

typedef union
{
	struct
	{
		unsigned int pair:2;
		unsigned int three_card:1;
		unsigned int straight:1;
		unsigned int flush:1;
		unsigned int full_house:1;
		unsigned int four_card:1;
		unsigned int straight_flush:1;	
	} result_bit;
	unsigned char result;
} card_result;

inline static char
value_to_integer(char a_value)
{
	switch ( a_value )
	{
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return a_value - '2';
	case 'T':
		return 8;
	case 'J':
		return 9;
	case 'Q':
		return 10;
	case 'K':
		return 11; 
	}
}

int main(void)
{
	card_game game;
	int       size = sizeof(game) + 1;
	int       checker[12];

	while ( fgets(&game, size, stdin) )
	{
		char shape = 0xFF;
		card_result r = { 0, };
		char min = 20;
		char max = -1;

		for ( int i = 0; i < 5; i++ )
		{
			char n = game.black[i].value = value_to_integer(game.black[i].value);
			checker[n]++;

			min = n < min ? n : min;
			max = max < n ? n : max;

			switch ( checker[n] )
			{
			case 2:
				r.result_bit.pair++;
				break;
			case 3:
				r.result_bit.three_card = 1;
				break;
			case 4:
				r.result_bit.four_card = 1;
				break;
			}

			shape = shape & game.black[i].shape;
		}

		r.result_bit.flush = (shape == game.black[0].shape);
		r.result_bit.full_house = (r.result_bit.pair == 2) && r.result_bit.three_card;

		if ( max - min == 4 )
		{
			for ( int i = min; i < max; i++ )
			{
				checker[i]
			}
		}
		else
		{
			r.result_bit.straight = 0;
		}
	}

	return 0;
}
