#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int shuffle_deck[103][53];


int debugMode = 0;
int debugMode2 =0;

#define ASSERT(func) \
{\
	int rt = 0;\
	rt = func;\
	if(rt != 0)\
	{\
		fprintf(stderr, "[ASSERT ERROR!][%s][%d] rt %d \n", __func__, __LINE__, rt);\
		return rt;\
	}\
}

#define DBG_PRINT(format, args...)\
{\
	if(debugMode)\
	printf(format, ##args);\
}

#define DBG_PRINT2(format, args...)\
{\
	if(debugMode2)\
	printf(format, ##args);\
}

int main(void)
{
	int i,j,k;
	int total_case = 0;
	char buf[512] = {0};
	int temp;
	int first_time;
	int src, dst;
	char *card_type[4] ={"Clubs", "Diamonds", "Hearts", "Spades"};
	char *card_deck[13] = {"2","3","4","5","6","7","8","9","10","Jack","Queen", "King", "Ace"};

	fgets(buf, sizeof(buf), stdin);
	total_case = atoi(buf);
	DBG_PRINT("total case %d \n", total_case);
	for(k = 1; k <= 52; k++)
	{
		shuffle_deck[0][k] = k;
	}

	fgets(buf, sizeof(buf), stdin);
	for(i = 0; i < total_case; i++)
	{
		int suffle_case = 0;
		fgets(buf, sizeof(buf), stdin);
		suffle_case = atoi(buf);
		DBG_PRINT("suffle case %d\n", suffle_case);
		for(j = 1; j <= suffle_case; j++)
		{
			char *token; 
			k = 1;
			fgets(buf, sizeof(buf), stdin);
			token = strtok(buf, " ");
			do{
				shuffle_deck[j][k] = atoi(token);
				DBG_PRINT2("[%d][%d] : %d\n",j,k, shuffle_deck[j][k]);
				k++;
			} while ((token = strtok(NULL, " ")) != NULL && k <= 52);
		}
		DBG_PRINT("start suffle!\n");
		first_time = 0;
		while(1)
		{
			int index = 0;
			fgets(buf, sizeof(buf), stdin);
			DBG_PRINT("index size %d\n", strlen(buf));
			if(strlen(buf) == 1)
			{
				DBG_PRINT("DBG Break\n");
				break;
			}
			index = atoi(buf);
			DBG_PRINT("index %d\n", index);

			if(first_time == 0)
			{
					src = 0;
					dst = 101;
					first_time = 1;
			}
			else
			{
				dst = (dst == 101) ? (102) : (101);
				src = (dst == 101) ? (102) : (101);
			}

			DBG_PRINT("src %d dst %d\n", src, dst);

			for(k = 1; k <= 52; k++)
			{
				shuffle_deck[ dst ][ k ] = 	shuffle_deck[ src ][ shuffle_deck[index][k] ];
				DBG_PRINT2("k %d shuffle_deck[index][k] = %d  dst %d\n", k, shuffle_deck[index][k], shuffle_deck[dst][k]);
			}
		}
	
		for(k = 1; k <= 52; k++)
		{
			int temp =  shuffle_deck[ dst ][ k];
			printf("%s of %s\n", card_deck[ (temp - 1) % 13], card_type[ (temp -1 ) / 13 ]); 
		}
		printf("\n");
	}
	return 0;
}
