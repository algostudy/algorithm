#include <stdio.h>
#define MAX 44722

int main()
{
	int i,j;
	int x,y;
	unsigned int pos[MAX];
	int chiper[10];
	unsigned int num = 10;
	pos[0] = 1;
	chiper[0] = 0;
	 

	for(i=1, j=1; i<MAX; i++)
	{
		pos[i] = pos[i-1] + (2 * i);
 		//printf("pos[%u] = %u\n", i, pos[i]);
	}
	while(scanf("%d", &i) == 1)
	{
		if(i == 0)
		{
			break;
		}

		for(j=MAX-1; j>=0 ;j--)
		{
			if(pos[j] <= i)
			{
				if(pos[j] == i)
				{
					x = y = j;
				}
				else if(pos[j] + j >= i)
				{
					int diff = i - pos[j];
					if((j) & 1)
					{
						x = j;
						y = j - diff;
					}
					else
					{
						x = j - diff;
						y = j;
					}
				}
				else
				{
					int diff = pos[j+1] - i;
					if((j+1) & 1)
					{
						x = j+1 - diff;
						y = j+1;
					}
					else
					{
						x = j+1;
						y = j+1 - diff;
					}
				}
				
				printf("%d %d\n",x+1,y+1);
				break;
			}
		}
	}
	return 0;
}
