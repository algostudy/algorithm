#include <stdio.h>

int
main()
{
	unsigned int input;
	int i,j;
	unsigned int prime[10000] = {2,3,5,7};
	int primeCount = 4;
	int count = 0;
	for(i=10; i<=70000; i++)
	{
		for(j=0; j<primeCount; j++)
		{
			//printf("i %d prime[%d] %d \n", i, j, prime[j]);
			if(i % prime[j] == 0)
			{
				break;
			}
		}
		
		if(j == primeCount)
		{
			prime[j] = i;
			//printf("%d ", prime[j]);
			primeCount++;
		}
	}

	//printf("\nprimeCount %d\n", primeCount);
	//return 0;
	while(1)
	{
		scanf("%u", &input);
		//printf("%u\n",input);
		if(input == 0)
		{
			return 0;
		}
		
		
		for(i=0; i<primeCount; i++)
		{
			if(input == 1)
			{
				printf("yes\n");
				break;
			}
			count = 0;	
			while(1)
			{
				//printf("%u %d\n", input, prime[i]);
				if(input % prime[i] == 0)
				{
					count++;
					input = input / prime[i];
				}
				else
					break;
			}
			if(count & 1)
			{
				printf("no\n");
				break;
			}			
		}				

		if(i == primeCount)
			printf("no\n");
	}

	return 0;
}
