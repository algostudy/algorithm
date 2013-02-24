#include <stdio.h>

typedef struct
{
	unsigned int straight_flush:1;
	unsigned int four_card:1;
	unsigned int full_house:1;
	unsigned int flush:1;
	unsigned int straight:1;
	unsigned int three_card:1;
	unsigned int pair:2;
} rule;

int main(void)
{
	int checker[20] = { 0, };
	int checker2[5] = { 0, };
	char* card[5] = { "1H", "2H", "3H", "4H", "5C" };
	char shape = 0xFF;
	int  pair = 0, three_card = 0, four_card = 0;
	int  n = 0;
	int  ch = 0;
	int  straight = 0;
	int  prev = 0;


	//int checker[14]

	for ( int i = 0; i < 5; i++ )
	{
		n = card[i][0] - '0';
		checker[n]++;
		ch = checker[n] > ch ? checker[n] : ch;
		pair = pair + (checker[n] == 2);
		//checker2[checker[n]]++;



	/*	if ( checker[n] == 2 )
			pair++;
		else if ( checker[n] == 3 )
			three_card++;
		else if ( checker[n] == 4 )
			four_card++;*/

		shape = shape & card[i][1];

		//printf("%d ", shape == card[0][1]);
	}

	for ( int i = 1; i < 20; i++ )
	{
		straight = straight + ((checker[i] - checker[i - 1]) == 1);
		checker[i] = 0;
	}

	printf("%d %d", straight, shape == card[0][1]);
	//printf("%d %d %d %d", checker2[1], checker2[2], checker2[3], checker2[4]);

	return 0;
}
