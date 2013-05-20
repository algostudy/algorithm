#include <stdio.h>


int main(void)
{
	FILE *fp;

	fp = fopen("input.txt", "rb");		
	if(fp == NULL)
	{
		fprintf(stderr, "fopen error!\n");
		return -1;
	}

	fclose(fp);
	return 0;
}
