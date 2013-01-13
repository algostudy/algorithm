
#include <stdio.h>
#include <string.h>
#define MAXLINE 50
#define CHAR_TO_INT 48

int
parseStrToArray(char* str, int* array)
{
	int i = 0;
	int size = (int)strlen(str);

	for(i = 0 ; i < size ; i++)
	{
		array[i] = (int)str[size -1 -i] - CHAR_TO_INT;		
	}
	return size;
}

int
main()
{
	int aArray[11] = {0};
	int bArray[11] = {0}; 
	int aNumDigit = 0;
	int bNumDigit = 0;
	int count = 0;
	int carryNum = 0;
	int i = 0;
	char buf[MAXLINE];

	int *sPtr;
	int *lPtr;
	int sCount = 0;
	int lCount = 0;

	while(fgets(buf, MAXLINE, stdin) != NULL)
	{
		char *p;
		p = strtok(buf, " ");			
		aNumDigit = parseStrToArray(p, aArray);	
		p = strtok(NULL, " \n");
		bNumDigit = parseStrToArray(p, bArray);
		
		if(aNumDigit == 1 && 
			bNumDigit == 1 &&
			aArray[0] == 0 &&
			bArray[0] == 0)
		{
			return 0;
		}

		if(aNumDigit < bNumDigit)
		{
			sPtr = aArray;
			lPtr = bArray;
			sCount = aNumDigit;
			lCount = bNumDigit;			
		}
		else
		{
			sPtr = bArray;
			lPtr = aArray;
			sCount = bNumDigit;
			lCount = aNumDigit;			
		}

		carryNum = 0;
		for(i = 0; i < sCount; i++)
		{
			int temp = sPtr[i] + lPtr[i];
			if(temp >= 10)
			{
				carryNum++;
				lPtr[i+1] += 1;
			}			
		}

		for( ; i < lCount  ; i++)
		{
			if(lPtr[i] >= 10)
			{
				carryNum++;
				lPtr[i+1] += 1;
			}
		}
		printf("%d\n",carryNum); 
	}

	return 0;
}
