#include <stdio.h>

#define ABS(int) (int < 0) ? (int * (-1)) : (int)

int relatives[500];

int
findCloseRel(int ave, int num)
{
	int distance = 30000;
	int temp = 0;
	int result = 0;
	int i = 0;
	for(i = 0; i < num ; i ++)
	{
		temp = relatives[i] - ave;
		temp = ABS(temp);
		
		printf("[%d] relatives[i] %d, ave %d, temp %d\n", i, relatives[i], ave, temp);
		if(temp <= distance)
		{
			distance = temp;
			result = i;	
			printf("result %d\n", result);
		}
	}

	printf("result : %d, distance : %d\n", result, distance);
	return result;
}

int
sort(int num)
{
	int i,j;
	int sorted = 0;

	while(!sorted)
	{
		sorted = 1;	
		for(i = 0 ; i < num - 1 ; i++)
		{
			if(relatives[i] > relatives[i+1])
			{
				int tmp = relatives[i];
				relatives[i] = relatives[i+1];
				relatives[i+1] = tmp;			
				sorted = 0;
			}
		}	
	}

	return 0;
}

int
main()
{
	int count = 0;
	int i = 0;
	int j = 0;
	int rel = 0;
	int num = 0;
	int sum = 0;
	int ave = 0;
	int closeRelative = 0;
	int val = 0;
	int temp = 0 ;

	scanf("%d", &count);
	count = 10;
	for(i = 0 ; i < count ; i++)
	{
		sum = 0;
		scanf("%d", &num);	
		for(j = 0 ; j < num ; j++)
		{
			scanf("%d", &rel);
			relatives[j] = rel;
			sum += rel;			
		}

		ave = sum / num;
		printf("sum %d, ave %d\n", sum, ave);
		#if 0
		closeRelative = findCloseRel(ave, num);
		val = relatives[closeRelative];
		
		sum = 0;
		for(j = 0 ; j < num ; j++)
		{
			temp = relatives[j] - val;
			temp = ABS(temp);
			sum += temp;			
		}
		printf("result : %d\n", sum);
		#else
		sort(num);
		for(j = 0 ; j < num ; j++)
		{
			printf("[%d] %d \n", j, relatives[j]);
		}
		val = relatives[num/2];
		printf("index %d = %d \n", relatives[num/2], num/2);
		sum = 0;
		for(j = 0 ; j < num ; j++)
		{
			temp = relatives[j] - val;
			temp = ABS(temp);
			sum += temp;			
		}
		printf("result : %d\n", sum);
		#endif
	}
	
	return 0;
}
