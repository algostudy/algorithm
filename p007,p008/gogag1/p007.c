#include <stdio.h>
#include <math.h>

int main()
{
	double a;
	unsigned int i;
	while(1){
 
		a=0, i=0;
 
		scanf("%lf", &a);
 
		if(a == 0)
		break;
		
		i = sqrt(a);
		
		if(a == i*i)
			printf("yes\n");
		else
		 	printf("no\n");
		fflush(stdout);
	 }
	
	return 0;
}
