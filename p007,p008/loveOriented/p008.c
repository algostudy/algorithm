#include <stdio.h>

#define MAX 8

void
cleanArray(int (*array)[MAX], int size)
{
	int i;
	int j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			array[i][j] = 0;
		}
	}
}

int
getTotalCases(int x, int y)
{
	int numOfTable = x * x;
	int i;
	int up = 1;	
	int down = 1;

	for(i=numOfTable; i>(numOfTable - y); i--)
	{
		up = up * i;
	}

	for(i=1; i<=y; i++)
	{
		down = down * i;
	}
	
	up = up / down;

	printf("cases %d\n", up);
	return 0;
}
unsigned int gCases;
int gNumOfTable;

void
setBishopAttackRange(int (*status)[MAX],int index, int value)
{
	int x,y;
	int i;
	int xFactor[] = {-1,-1,1,1};
	int yFactor[] = {-1,1,-1,1};


	x = index / gNumOfTable;
	y = index % gNumOfTable;

	//printf("index %d\n", index);
	//printf("[x][y] = [%d][%d]\n", x,y);
	for(i=0; i<4; i++)
	{		
		int tempX = x;
		int tempY = y;
		while(1)
		{
			tempX = tempX + xFactor[i];
			tempY = tempY + yFactor[i];			
			if((tempX>= 0 &&  tempY>= 0) && (tempX< gNumOfTable || tempY < gNumOfTable) )
			{
				//printf("tempX %d tempY %d, %d %d\n", tempX, tempY, xFactor[i], yFactor[i]);
				status[tempX][tempY] += value;
			}
			else
			{
				break;
			}
		}
	}
}


void
setBishop(int (*array)[MAX], int (*status)[MAX], int x, int y)
{
	int i;
	//무식하게 풀자
	for(i=x; i<gNumOfTable * gNumOfTable; i++)
	{
		//1. 비숍 세팅 위치
		//공격 루트 인가?
		printf("i = %d\n", i);
		if(status[i / gNumOfTable][i % gNumOfTable] >= 1)
		{
			//printf("status >= 1\n");
			//돌아간다.
			continue;
		}
		else
		{
			//이 비숍이 마지막 비숍인가?
			if(y == 1)
			{
				gCases++;
				printf("safe cases: %d\n", gCases);
				continue;
			}
			else
			{
				//현재 비숍 세팅
				array[i / gNumOfTable][i % gNumOfTable] = 1;
				printf("set [%d][%d] \n", i / gNumOfTable,i % gNumOfTable);
				setBishopAttackRange(status, i,1);
				//printf("setBishop %d, %d\n", i+1, y-1);
				//다음 비숍 배치하자
				setBishop(array, status, i+1, y-1);
				//자기 위치 정리
				array[i / gNumOfTable][i % gNumOfTable] = 0;
				setBishopAttackRange(status, i,-1);
			}
		}

	}
	printf("end bishop!\n");
}

int
main()
{
	int table[MAX][MAX] = {0};
	int status[MAX][MAX] = {0};
	int x,y;
	int cases;

	while(scanf("%d %d",&x, &y) == 2)
	{
		if(x == 0 && y == 0)
		{
			return 0;
		}
	
		//printf("x %d y %d\n", x,y);

		cleanArray(table, x);
		cleanArray(status,x);
		
		gCases = 0;
		gNumOfTable = x;
		
		//printf("gNumOfTable %d\n", x);
		setBishop(table, status, 0, y);
		printf("%u\n", gCases);
	}

	return 0;
}

