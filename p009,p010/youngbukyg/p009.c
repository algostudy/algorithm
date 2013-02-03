#include <stdio.h>
int main()
{
		int n=0, i=0, cond=0;
	while(1)
	{
		n=0, i=0, cond=0;
		printf("n = %d\ni = %d\ncond = %d\n",n, i, cond);


		//node inserted
		printf("start p009\nbefore insterting inputs\n");
		scanf("%d",&n);
		printf("n = %d\ni = %d\ncond = %d\n",n, i, cond);

		// when 0 is inserted , app muse be stop.
		if(n==0)
			return 0;

		//i inserted
		scanf("%d",&i);
		printf("n = %d\ni = %d\ncond = %d\n",n, i, cond);
		printf("-----------------------/\n completed..\n");
	
		
		cond = i % 2;
		printf("n = %d\ni = %d\ncond = %d\n",n, i, cond);
		if(cond)
			printf("NOT BICOLORABLE\n");
	
		else	
			printf("BICOLORABLE\n");
	
		n=0, i=0, cond=0;
	
		printf("========I'm very sorry there are no summit to solve the problems\n I will do my best in this week========\n");
	}

}
