
#include <stdio.h>
#include <stdlib.h>

int start[4];
int goal[4];
int **limit;
int num_limit;

int is_this_paht_right(int *current)
{
	int i,j;
	int diff;
	for(i = 0; i < num_limit; i++)
	{
		diff = 0;
		for(j = 0; j < 4; j++)
		{
			if(current[j] != limit[i][j])
				diff = 1;
		}
		if(diff == 0)
			return 0;
	}
	return 1;
}

static int sta_get_min_path(int *current) 
{
	//check
	if(! is_this_paht_right(current))
	{
		printf("wrong path!\n");
		return 0;
	}
	return 1;
}

int get_min_path()
{
	int i;
	int current[4];
	int result;
	
	for(i = 0; i < 4; i++)
		current[i] = start[i];

	printf("current %d %d %d %d\n", current[0], current[1], current[2], current[3]);
	sta_get_min_path(current);

	return result;
}

int main(void)
{
	int num_case;

	scanf("%d", &num_case);
	printf("%d\n", num_case);

	while(num_case--)
	{
		int i, j;
		int result;
		for(i = 0; i < 4; i++)
		{
			scanf("%d", &start[i]);
			printf("%d\n", start[i]);
		}
		
		for(i = 0; i < 4; i++)
		{
			scanf("%d", &goal[i]);
			printf("%d\n", goal[i]);
		}
		scanf("%d", &num_limit);
		limit = (int **)malloc( sizeof(int *) * num_limit);
		limit[0] = (int *)malloc( sizeof(int) * num_limit * 4 );
		for(j = 1; j < num_limit; j++)
		{
			limit[j] = limit[ j-1 ] + 4;
		}
		
		for(i = 0; i < num_limit; i++)
		{
			for(j = 0; j < 4; j++)
			{
				scanf("%d", &limit[i][j]);
				printf("%d ", limit[i][j]);
			}
			printf("\n");
		}
	
		// TO DO-START
		result = get_min_path();
		// TO DO-END


		free(limit[0]);
		free(limit);
	}


	return 0;
}
