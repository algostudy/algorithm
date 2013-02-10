#include <stdio.h>

int main()
{
	unsigned long long a[101];
	int i, num;
	a[0] = 1;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	a[4] = 1;

	for(i=5; i<101; i++)
	{
		a[i] = a[i-2] + a[i-3] + a[i-5];
		//printf("a[%d] = %llu\n", i, a[i]);
	}

	while(scanf("%d", &num) == 1)
	{
		if(num == 0)
		{
			break;
		}
		printf("%llu\n", a[num]);
	}
	return 0;
}
