#include <stdio.h>
#include <string.h>
#define MAXLINE 256

unsigned int array[100001];
unsigned int arrayTemp[1000001];
char buf[MAXLINE];

int 
getNextNum(unsigned int num)
{
	if(num % 2 == 0)
	{
		return (num / 2);
	}
	else
	{
		return (num * 3 + 1);	
	}
}


int
getPathSize(int num)
{
	int count = 0;
	int tempResult = 0;

	array[1] = 1;
	if(array[num] != 0)
	{
		//printf("first find! %d:%d\n", num , array[num]);
		return array[num];
	}
	
	tempResult = num;
	arrayTemp[count] = tempResult;
//	count = 1;
	while(1)
	{
		tempResult = getNextNum(tempResult);
		//printf("[%d] tempResult %d\n", count, tempResult);
		count++;		

		if(tempResult > 1000000)
		{
			//printf("over 1,000,000! %d \n", tempResult);
			arrayTemp[count] = 0;
			continue;
		}
		if(array[tempResult] != 0)
		{
			int x = 0;
			int index = 0;
			int i = 0;
			//save previous path
			x = array[tempResult];
			//printf("middle x %d index %d\n", x , tempResult);
			for(i=0; i<count; i++)
			{
				index = arrayTemp[i];
				
				array[index] = x + count - i;
				//printf("array[%d] = %d\n", index, x+count-i);
				arrayTemp[i] = 0;
			}
			return array[num];
		}		
		arrayTemp[count] = tempResult; 
	}	
}


int
findLongestNumTwo(int startNum, int endNum)
{
	int result = 0;
	int tempResult = 0;
	int i = 0;
	int j = 0;

	for(i = startNum; i <= endNum; i++)
	{		
		//printf("\n==============start\n");
		tempResult = getPathSize(i);
		//printf("[%d] num of path %d\n", i, tempResult);
		//printf("================end\n");
		if(result < tempResult)
		{
			result = tempResult;
		}
	}

	return result;
}


int
findLongestNum(int startNum, int endNum)
{
	int result = 0;
	int tempResult = 0;
	int i = 0;
	int j = 0;
	int count = 0;

	for(i = startNum; i<=endNum; i++)
	{
		tempResult = i;
		count = 1;
		while (1)
		{
			if(tempResult == 1)
				break;
			tempResult = getNextNum(tempResult);
			count++;
			printf("[%d:%d] tempResult %d\n", i, count,  tempResult); 
			if(tempResult == 1)
			{
				break;
			}			
		}
		if(result < count)
		{
			result = count;
		}


		printf("%d %d \n", i, count);


	}

	return result;
}


int
main()
{
	int startNum = 0;
	int endNum = 0;
	int result = 0;
	int c = 0;

	while(fgets(buf, MAXLINE, stdin) != NULL)
	{
		char *p;
		p = strtok(buf, " ");
		startNum = atoi(p);
		p = strtok(NULL, " ");
		endNum = atoi(p);
			
		//printf("%d %d\n", startNum, endNum);
		//result = findLongestNum(startNum, endNum);
		result = findLongestNum(startNum, endNum);
		//sprintf(buf, "%d %d %d\n", startNum, endNum, result);
		//fputs(buf, stdout);
		printf("%d %d %d\n", startNum, endNum, result);
	}	
	return 0;
}
