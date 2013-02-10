#include <stdio.h>
#include <math.h>

int main()
{
		int x,y;
		int num, middle, diff;
		int index;
		double sqrt_num;
		while(scanf("%d", &num) == 1)
		{
				if(num == 0)
				{
						break;
				}

				sqrt_num = sqrt(num);
				index = (int)sqrt_num;

				if( index == sqrt_num )
				{
						index--;
				}

				middle = (index+1) * (index+1) - index;
				//printf("middle %d\n", middle);
				//printf("index %d\n", index);
				diff = num - middle;
				//printf("dif  %d\n", diff);
				if( index & 1 )
				{
					x = (diff < 0) ? (index + diff) : (index);
					y = (diff < 0) ? (index) : (index - diff);
				}
				else
				{
					x = (diff < 0) ? (index) : (index - diff);
					y = (diff < 0) ? (index + diff) : (index);
				}	
				printf("%d %d\n",x+1, y+1);
		}
		return 0;
}
