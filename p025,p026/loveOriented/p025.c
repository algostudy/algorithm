#include <stdio.h>
#include <string.h>

char input_str[10001];
char input_str_org[10001];
char sub_str[101];
int input_size;
int sub_size;
unsigned long long count;


void search_word(int start, int sub_index)
{
	int i;
	if(start > input_size)
	{	
		return;
	}

	if(sub_index > sub_size)
	{	
		return;
	}
	
	for(i = start; i < input_size; i++)
	{
			if(input_str[i] == sub_str[sub_index])
			{
					if(sub_index == sub_size -1)
					{
							count++;
					}
					else
					{
						search_word(i+1, sub_index + 1); 
					}
			}
	}
}

int char_ary[26];
int input_index;

void cut_unused_char()
{
		static int marker = 1;
		int i;
		input_size = strlen(input_str_org);
		sub_size = strlen(sub_str);
		for(i = 0; i < sub_size; i++)
		{
				int temp = sub_str[i] - 97;
				if(char_ary[temp] != marker)
				{
						char_ary[temp] = marker;
				}
		}
		input_index = 0;	
		for(i = 0; i < input_size; i++)
		{
				int temp = input_str_org[i] - 97;
				if(char_ary[temp] == marker)
				{	
						input_str[input_index++] = input_str_org[i];
				}
		}

		marker++;	
}

int main(void)
{
	int num_case;

	scanf("%d", &num_case);
	while(num_case)
	{
		scanf("%s", &input_str_org);
		scanf("%s", &sub_str);
		//algorithm
		cut_unused_char();
		count = 0;
		input_size = input_index;
		search_word(0, 0);
		printf("%d\n",count);
		num_case--;
	}
	return 0;
}
