#include <stdio.h>
#include <math.h>

int
main()
{
	unsigned int input;
	unsigned int input2;
	int i,j;
	while(1)
	{
		scanf("%u", &input);
		if(input == 0)
		{
			return 0;
		}
		
		input2 = (int)sqrt(input);
		if(input2 * input2 == input)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	return 0;
}
