#include <stdio.h>
#include <string.h>
#define MAXLINE 250
#define CHAR_TO_INT 48

int fibArray[500][101]; 
int fibSizeArray[500];

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

void
fib2(int n)
{
	int i = 0;
	int *n_1Ptr = fibArray[n-1];
	int *n_2Ptr = fibArray[n-2];
	int *nPtr = fibArray[n];

	for(i = 0; i < fibSizeArray[n-1]; i++)
	{
		nPtr[i] = nPtr[i] + n_1Ptr[i] + n_2Ptr[i];
		//printf("nPtr[%d]:%d, n_1Ptr[%d]:%d, n_2Ptr[%d]:%d\n",
		//	i, nPtr[i], i, n_1Ptr[i], i, n_2Ptr[i]);
			
		if(nPtr[i] >=10)
		{
			nPtr[i+1] += 1;
			nPtr[i] -= 10;
		}
	}

	if(nPtr[i] > 0)
	{
		fibSizeArray[n] = i +1;
	}
	else
	{
		fibSizeArray[n] = i; 
	}
}

void
fib(int n)
{
	int i = 0;
	int j = 0;
	fibArray[0][0] = 1;
	fibSizeArray[0] = 1;
	fibArray[1][0] = 1;
	fibSizeArray[1] = 1; 

	for(i=2; i<=n ; i++)
	{	
		fib2(i);
	
		#if 0
		printf("fib [%d] is ", i);
		for(j =0; j< fibSizeArray[i]; j++)
		{
			printf("%d", fibArray[i][fibSizeArray[i] - 1 -j]);
		}
		printf("\n");
		#endif
	}
}

int
isLeftBig(int* a,int aSize,  int* b, int bSize)
{
	int i = 0;

	if(aSize > bSize)
	{
		//printf("aSize > bSize \n");
		return 1;
	}
	else if(aSize < bSize)
	{
		//printf("aSize < bSize \n");
		return 0;
	}

	for(i=aSize -1; i >=0; i--)
	{
		//printf("a[%d] %d b[%d] %d\n", i,a[i], i, b[i]);
		if(a[i] > b[i])
		{
			return 1;
		}
		else if(a[i] == b[i])
		{
		
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

/*contain some issuses might cause segmentation fault*/
int
getNumOfFib(int* a,int aSize,  int* b, int bSize)
{
	int i = 0;
	int j = 0;
	int count = 0;

	i = 1;
	while(fibSizeArray[i] < aSize)
	{
		//printf("fibSizeArray[%d] : %d , aSize %d \n",i, fibSizeArray[i], aSize);
		i++; 
	}

	//printf("i %d\n", i);	

	while(1)
	{
		if(isLeftBig(fibArray[i], fibSizeArray[i], a, aSize))
		{
			break;
		}
		i++;
	}
	
	//printf("i %d\n", i);	
	while(1)
	{
		if(isLeftBig(b, bSize, fibArray[i], fibSizeArray[i]))
		{
			count++;	
		}
		else
		{
			break;
		}
		i++;
	}

	return count;
}


int
main()
{
	int aArray[101] = {0};
	int bArray[101] = {0}; 
	int aNumDigit = 0;
	int bNumDigit = 0;
	int count = 0;
	int num = 0;
	int i = 0;
	char buf[MAXLINE];

	int *sPtr;
	int *lPtr;
	int sCount = 0;
	int lCount = 0;

	//Actually, I counted that which fib(n)'s digit nums is 10^100.
	fib(483); 

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

		num = getNumOfFib(aArray,aNumDigit, bArray,bNumDigit);
		printf("%d\n",num); 
	}

	return 0;
}
