/**
 * 2012 / 12 / 31 지노지노
 * 행님 저희 서버는 싱글 코어라서 멀티스레드가 더 느립니다ㅜ
 * 그리고 arrayJolly에 있는 값 세팅하고 검사하는 부분이 스레드 동기화가 안되어있네요.
 * 상수라서 큰 문제는 없긴 한데 동기화 비용 때문에 일부러 빼신거 아니라면 스레드 언세이프인 것 같음.
 **/
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#define MAXLINE 10000000
int array[5000];
int arrayJolly[5000];
char buf[MAXLINE];

#define ABS(int) (int < 0) ? (int * (-1)) : (int)

int gWait1;
int gWait2;
int gError1;
int gError2;
int mid;
int gNum;
void* a_thr(void *arg)
{
	int i;
	int tempA;
	printf("[%s]\n", __FUNCTION__);
	while(1)
	{
		while(gWait1 == 0);

		for(i=0;i <mid;i++)
		{
			tempA = array[i] - array[i+1];
			tempA = ABS(tempA);
		
			if(gError2 == 1)
			{
				gWait1 = 0;
				break;
			}

			printf("[%s]tempA = %d\n", __FUNCTION__,tempA);
			if(arrayJolly[tempA] == 0 && tempA < gNum)
			{
				arrayJolly[tempA] = 1;
			}
			else
			{
		printf("[%s] why \n", __FUNCTION__);
				
				gError1 = 1;
				gWait1=0;
				break;
			}
		}
		printf("[%s] break \n", __FUNCTION__);

	}
	
}

void* b_thr(void *arg)
{
	int i;
	int tempA;
	printf("[%s]\n", __FUNCTION__);
	while(1)
	{
		while(gWait2 == 0);

		for(i=mid;i <gNum;i++)
		{
			tempA = array[i] - array[i+1];
			tempA = ABS(tempA);
		
			if(gError1 == 1)
			{
				gWait2= 0;
				break;
			}
			printf("[%s]tempA = %d\n", __FUNCTION__,tempA);
			if(arrayJolly[tempA] == 0 && tempA < gNum)
			{
				arrayJolly[tempA] = 1;
			}
			else
			{
				gError2 = 1;
				gWait2=0;
				break;
			}
			
		}
		printf("[%s] break \n", __FUNCTION__);
	}
}

int
isLineJolly(int num)
{
	int gNum = num - 1;
	int i = 0;
	int tempA;
	int tempB;
	memset(arrayJolly, 0, num * sizeof(int));

	mid = gNum / 2;
	gWait1 = 1;
	gWait2 = 1;
	gError1 = 0;
	gError2 = 0;

	while(1)
	{
		while(1)
		{
			if(gWait1 == 0 && gWait2 == 0)
			{
				if(gError1 == 1 || gError2 == 1)
				{
					return -1;
				}
				else return 0;
			}
		
		}
	}

#if 0
	for(i=0;i < num - 1; i++)
	{
		//tempA = ABS(array[i] - array[i+1]);
		//tempA = array[i] - array[i+1];
		//tempA = ABS(tempA);
		//tempB = count; 
	
		//tempA = array[i] - count;
		tempA = array[i] - array[i+1];
		tempA = ABS(tempA);
		
		//printf("tempA = %d\n", tempA);
		if(arrayJolly[tempA] == 0 && tempA < num)
		{
			arrayJolly[tempA] = 1;
		}
		else
		{	
			return -1;	
		}
		
	
		//printf("i %d, array[i] %d, array[i+1] %d\n", i, array[i], array[i+1]);

		/*
		//printf("A %d B %d\n", tempA, tempB);
		if((int)tempA == (int)tempB)
		{
			//printf("array[%d]%d - array[%d]%d ==%d %d\n", i, array[i], i+1, array[i+1], array[i] - array[i+1],  ABS(count));
			count--;
		}
		#if 0
		if((signed int)(array[i] - array[i+1])  ==(signed int) ABS(count))
		{
			printf("array[%d]%d - array[%d]%d ==%d %d\n", i, array[i], i+1, array[i+1], array[i] - array[i+1],  ABS(count));
			count--;
		}
		#endif
		else
		{
			return -1;
		}*/
	}

#endif
	return 0;
}


int
main()
{
	int num = 0;
	int i = 0;
	int result = 0;

	pthread_t t_id;

	pthread_create(&t_id,NULL, a_thr, NULL);
	pthread_detach(t_id);
		
	pthread_create(&t_id,NULL, b_thr, NULL);
	pthread_detach(t_id);

	while(fgets(buf, MAXLINE, stdin) != NULL)
	{	
		char *p;
		p = strtok(buf, " ");
		num = atoi(p);
		//printf("num %d ", num);
		for(i=0;i<num;i++)
		{	
			p = strtok(NULL, " ");		
			array[i] = atoi(p);
		}
		
		//printf("\n\n ");
		result = isLineJolly(num);
		if(result != 0)
		{
			printf("Not jolly\n");
		}
		else
		{
			printf("Jolly\n");
		}

	}	

	return 0;
}
