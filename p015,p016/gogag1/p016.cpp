#include <iostream>
#include <cstring>

using namespace std;

#define HC 1
#define OP 2
#define TP 3
#define TH 4
#define ST 5
#define FL 6
#define FH 7
#define FO 8
#define SF 9

bool isFL(char **b)
{
	return b[0][1]==b[1][1]==b[2][1]==b[3][1]==b[4][1];
}

void AtoI(char **b, int *bn)
{
	for(int i=0; i<5; i++)
	{
		if(b[i][0] > '1' && b[i][0] <='9')
			bn[i] = b[i][0] - '0';
		else if(b[i][0] == 'T')
			bn[i] = 10;
		else if(b[i][0] == 'J')
			bn[i] = 11;
		else if(b[i][0] == 'Q')
			bn[i] = 12;
		else if(b[i][0] == 'K')
			bn[i] = 13;
		else if(b[i][0] == 'A')
			bn[i] = 14;
	}
}

void full(int *bn, int *black, bool *bs)
{
	int i=0;
	
	for(i=0; i<5; i++)
		black[bn[i]]++;

	for(i=0; i<15; i++)
	{
		if(black[i]==1)
		{
			*bs = black[i]==black[i+1]==black[i+2]==black[i+3]==black[i+4];
			break;
		}
	}		
}

int main()
{
	char *b[5], *w[5];
	int bn[5], wn[5];
	bool bs=false, ws=false;	
	
	while(){
		cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4];
		cin >> w[0] >> w[1] >> w[2] >> w[3] >> w[4];

		int black[15]={0,}, white[15]={0,};

		
	}	
		

	return 0;
}
