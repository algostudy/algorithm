#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	NUM 100000

int list[NUM];

void quick_pivot(int start, int end, int *pivot)
{
	int i,j;
	int pivotVal;
	int temp;

	pivotVal = list[start];
	j = start;
	for(i = start + 1; i <= end; i++)
	{
			if(list[i] < pivotVal)
			{
					j++;
					temp = list[i];
					list[i] = list[j];
					list[j] = temp;
			}
	}
	*pivot = j;

	temp = list[j];
	list[j] = list[start];
	list[start] = temp;
}

void quick(int start, int end)
{
		int pivot;

		if(end > start)
		{
			quick_pivot(start, end, &pivot);
			quick(start, pivot);
			quick(pivot+1, end);
		}
}

int main(void)
{
		int test_num;
		int list_num;

		/*
		   char * line = NULL;
		   size_t len = 0;
		   ssize_t read;

		   int count = 0;
		   char *after;
		 */
		int i;

		scanf("%d", &test_num);
		//printf("test_num %d\n", test_num);
		while(test_num--)
		{
				scanf("%d", &list_num);	
				//printf("list_num %d\n", list_num);
				for(i = 0; i < list_num; i++)
				{
						scanf("%d", &list[i]);
						//printf("list[%d] = %d\n", i, list[i]);
				}	


				quick(0, list_num-1);

				for(i = 0; i < list_num; i++)
				{
						//printf("list[%d] = %d\n", i, list[i]);
						printf("%d", list[i]);
				}	
				printf("\n");



				/*
				   read = getline(&line, &len, stdin); 
				   printf("Retrieved line of length %zu :\n", read);
				   printf("%s\n", line);

				   count = 0;
				   after = strtok(line, " ");
				   while(after != NULL)
				   {
				   list[count++] = atoi(after);
				   after = strtok(NULL, " ");
				   }

				   for(i = 0; i < count; i++)
				   printf("list[%d] = %d\n", i, list[i]);

				   if (line)
				   free(line);

				 */	
		}








		return 0;
}
