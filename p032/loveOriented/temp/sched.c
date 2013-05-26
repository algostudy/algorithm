#include <stdio.h>
#include <stdlib.h>


typedef enum eProcessMode
{
	KERNEL = 0,
	USER
} eProcessMode;

typedef struct stProcessInfo
{
	eProcessMode eMode;
	int	niceValue;
	int basePriority;
	int currentPriority;
	int runningTime;
	int cpuCount;
}stProcessInfo;

int gCpuTick = 60;

int isProcDone(stProcessInfo *stProcPtr)
{
	return (stProcPtr->runningTime == 0) ? (1) : (0);
}


int areAllProcsDone(stProcessInfo *stProcPtr, int num)
{
	int rt = 1; 
	int i;

	for( i = 0; i < num; i++)
	{
		if(!isProcDone(&stProcPtr[i]))
		{
			rt = 0;
			break;
		}
	}

	return rt;
}

void calProcPrior(stProcessInfo *stProcPtr)
{
	stProcPtr->cpuCount = stProcPtr->cpuCount >> 1;
	stProcPtr->currentPriority = (stProcPtr->cpuCount >> 1) + stProcPtr->basePriority + stProcPtr->niceValue;
	return;	
}

void runPorc(stProcessInfo *stProcPtr)
{
	stProcPtr->cpuCount += gCpuTick;
	stProcPtr->runningTime -= 1;
	return;
}


void calAllProcsPrior(stProcessInfo *stProcPtr, int num)
{
		int i;

		for( i = 0; i < num; i++)
		{
				calProcPrior(&stProcPtr[i]);
		}

	return;
}

int getProcsWithLowestPrior(stProcessInfo *stProcPtr, int num)
{
	int i;
	int lowPrior = 65536;
	int index = -1;

	for( i = 0; i < num; i++)
	{	
		if(stProcPtr[i].runningTime != 0 && stProcPtr[i].currentPriority < lowPrior)
		{
			lowPrior = stProcPtr[i].currentPriority;
			index = i;
		}
	}
	
	if(index == -1)
	{
		fprintf(stderr, "%s error!\n", index);
	}

	return index;
}

void printProcsStatus(stProcessInfo *stProcPtr, int num)
{
	int i;

	
	for( i = 0; i < num; i++)
	{
		printf("%d/%d\t", stProcPtr[i].runningTime, stProcPtr[i].currentPriority);
	}
	printf("\n");
	return;
}

int main(void)
{
	stProcessInfo *stProcessPtr;
	int num_process;
	eProcessMode eMode; 
	int i,j;
	int proc_index;
	
	//Data를 받는 부분
	printf("how many process ? : ");
	scanf("%d", &num_process);

	stProcessPtr = (stProcessInfo*)malloc(num_process * sizeof(stProcessInfo));
	printf("(total %d)\n", i+1, num_process);

	for( i = 0; i < num_process; i++)
	{
		printf("set process mode(0:kernel, 1:user)  : ");
		scanf("%d", &stProcessPtr[i].eMode);
		
		printf("set process priority  : ");
		scanf("%d", &stProcessPtr[i].basePriority);

		printf("set process running time  : ");
		scanf("%d", &stProcessPtr[i].runningTime);
		
	}


	printf("\n");

	for( i = 0; i < num_process; i++)
	{
		printf("process[%d] mode/priority/time : %d/%d/%d\n", i+1, stProcessPtr[i].eMode, stProcessPtr[i].basePriority, stProcessPtr[i].runningTime);
	}
	
	printf("remain time / current priority\n");

	while(!areAllProcsDone(stProcessPtr,num_process))
	{
		calAllProcsPrior(stProcessPtr, num_process);

		//CUI func
		printProcsStatus(stProcessPtr, num_process);
		proc_index = getProcsWithLowestPrior(stProcessPtr, num_process);
		runPorc(&stProcessPtr[proc_index]);

		//CUI func
		//printProcRunning(stProcessPtr[proc_index]);
	}

	return 0;
}
