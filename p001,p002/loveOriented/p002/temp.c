#include <stdio.h>
#include <string.h>




int main()
{
	int array[10];
	int i = 0;

	printf("sizeof(array)/int %d \n", sizeof(array)/sizeof(int));
	memset(array, 0, sizeof(array));

	for(i=0; i< sizeof(array)/sizeof(int); i++)
	{
		printf("0x%x ", array[i]);
	}
	printf("\n");

	memset(array, 0xFF, 5 * sizeof(int));

	for(i=0; i< sizeof(array)/sizeof(int); i++)
	{
		printf("0x%x ", array[i]);
	}
	printf("\n");

	memset(array, 0, 3 * sizeof(int));
	for(i=0; i< sizeof(array)/sizeof(int); i++)
	{
		printf("0x%x ", array[i]);
	}
	printf("\n");

	printf("\n");
	return 0;
}
