#include <stdio.h>
#include <string.h>

char input_str[10001];
char sub_str[101];
int input_size;
int sub_size;
unsigned long long count;


void search_word(int start, int sub_index)
{
	int i;
	//printf("[%s] start %d sub_index %d\n", __FUNCTION__, start, sub_index);

	if(start > input_size)
	{	
		//printf("over input_size\n");
		return;
	}

	if(sub_index > sub_size)
	{	
		//printf("over sub_size\n");
		return;
	}
	
	for(i = start; i < input_size; i++)
	{
			if(input_str[i] == sub_str[sub_index])
			{
					if(sub_index == sub_size -1)
					{
		//					printf("match! start %d sub_index %d i %d\n", start, sub_index, i);
							count++;
					}
					else
					{
						search_word(i+1, sub_index + 1); 
					}
			}
	}
}

int main(void)
{
	int num_case;

	scanf("%d", &num_case);
	while(num_case)
	{
		scanf("%s", &input_str);
		//printf("%s\n", input_str);
		scanf("%s", &sub_str);
	//	printf("%s %d\n", sub_str, strlen(sub_str));

		input_size = strlen(input_str);
		sub_size = strlen(sub_str);
		//algorithm
		count = 0;
		search_word(0, 0);
		

		printf("%d\n",count);
		num_case--;
	}
	return 0;
}
