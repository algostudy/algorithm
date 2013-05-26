#include <stdio.h>

const char* ordered_cards[] = {
	NULL,

	"2 of Clubs", "3 of Clubs", "4 of Clubs", "5 of Clubs", "6 of Clubs",
	"7 of Clubs", "8 of Clubs", "9 of Clubs", "10 of Clubs",
	"Jack of Clubs", "Queen of Clubs", "King of Clubs", "Ace of Clubs",

	"2 of Diamonds", "3 of Diamonds", "4 of Diamonds", "5 of Diamonds", "6 of Diamonds",
	"7 of Diamonds", "8 of Diamonds", "9 of Diamonds", "10 of Diamonds",
	"Jack of Diamonds", "Queen of Diamonds", "King of Diamonds", "Ace of Diamonds",

	"2 of Hearts", "3 of Hearts", "4 of Hearts", "5 of Hearts", "6 of Hearts",
	"7 of Hearts", "8 of Hearts", "9 of Hearts", "10 of Hearts",
	"Jack of Hearts", "Queen of Hearts", "King of Hearts", "Ace of Hearts",

	"2 of Spades", "3 of Spades", "4 of Spades", "5 of Spades", "6 of Spades",
	"7 of Spades", "8 of Spades", "9 of Spades", "10 of Spades",
	"Jack of Spades", "Queen of Spades", "King of Spades", "Ace of Spades"
};

const char*  storage[2][53];
const char** input_deck;
const char** output_deck = storage[0];
int          methods[101][53];

int main(void)
{
	int t;
	int n;
	int method_number;

	scanf("%d", &t);
	for ( int ti = 0; ti < t; ti++ )
	{
		scanf("%d", &n);

		for ( int ni = 0; ni < n; ni++ )
			for ( int ci = 1; ci <= 52; ci++ )
				scanf("%d", &methods[ni + 1][ci]);

		// init (set ordered cards)
		input_deck = ordered_cards;
		for ( int ni = 0; ni < n; ni++ )
		{
			// storage swap
			output_deck = storage[(output_deck - storage[0] + 1) % 2];

			// shuffle
			scanf("%d", &method_number);
			for ( int ci = 1; ci <= 52; ci++ )
				output_deck[ci] = input_deck[methods[method_number][ci]];

			// storage swap
			input_deck = output_deck;
		}

		for ( int ci = 1; ci <= 52; ci++ )
			printf("%s\n", output_deck[ci]);

		printf("\n");
	}
}
