#include <stdio.h>

void dec_to_bin(int num)
{
	int re = 0;
	if(num <= 1)
	{
		printf("%d",num);
		return;
	}
	
	re = num % 2;
	num = num >> 1;

	dec_to_bin(num);
	printf("%d", re);
	return;
}

int main(void)
{
	int test_num;
	
	scanf("%d", &test_num);
	
	while(test_num--)
	{
		int demical;
		scanf("%d", &demical);
		dec_to_bin(demical);
		printf("\n");
	}
	return 0;
}
