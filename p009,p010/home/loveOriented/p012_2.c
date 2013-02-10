#include <stdio.h>

//ine MAX 65535
#define MAX 44722
//#define MAX 45000

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
		if(pos[i] >= num && j <=9)
		{
			chiper[j] = i;
			num *= 10;
			//	printf("chiper[%d] = %d\n",j,i);
			j++;
		}
 		//printf("pos[%u] = %u\n", i, pos[i]);
	}
	while(scanf("%d", &i) == 1)
	{
		if(i == 0)
		{
			break;
		}

		num = 1000000000;
		for(j=9; j>=0; j--)
		{
			if(i>=num)
			{
				j=chiper[j];
				break;
			}
		
			num /= 10;
		}


		for(;j<MAX;j++)
		{
			if(pos[j] >= i)
			{
				if(pos[j] == i)
				{
					x = y = j;
				}
				else if(pos[j-1] + j-1 >= i)
				{
					int diff = i - pos[j-1];
					if((j-1) & 1)
					{
						x = j-1;
						y = j-1 - diff;
					}
					else
					{
						x = j-1 - diff;
						y = j-1;
					}
				}
				else
				{
					int diff = pos[j] - i;
					if((j) & 1)
					{
						x = j - diff;
						y = j;
					}
					else
					{
						x = j;
						y = j - diff;
					}
				}
				
				printf("%d %d\n",x+1,y+1);
				break;
			}
		}
	}
	return 0;
}
