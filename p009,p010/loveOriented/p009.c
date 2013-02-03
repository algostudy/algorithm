#include <stdio.h>
//#define DEBUG
#define MAX 200

int graph[MAX][MAX];
int vcolor[MAX];

int connect = 1;
int num;
int result;

int promising(int i)
{
	int j;
	int s;

	s = 1;
	j = 1;

	while(j < i && s)
	{
		if(graph[i][j] == connect && vcolor[i] == vcolor[j])
		{
			s = 0;
		}
		j++;
	}
	return s;
}

int m_coloring(int i)
{
	int color;
		
	#ifdef DEBUG
	printf("%s, %d\n",__FUNCTION__, i);
	#endif
	if(promising(i))
	{
		if(i == num)
		{
			result = 1;
			#ifdef DEBUG
			printf("BICOLORABLE case\n");
			#endif
			return result;
		}
		else
		{
			
			#ifdef DEBUG
			printf("promising %d \n", i);
			#endif
			for(color = 1; color <= 2; color++)
			{
				vcolor[i+1] = color;
				m_coloring(i+1);
				if(result == 1 || result == -1)
					return result;
			}
			result = -1;
			return result;
		}
	}
	
			#ifdef DEBUG
			printf("not promising %d \n", i);
			#endif
}

int
main()
{	
	int a, b;
	int i;
	int x, y;
	while(1)
	{
		scanf("%d", &b);
		num = b;
		#ifdef DEBUG
		printf("vertex %d\n", num);
		#endif
		
		if(b == 0)
			break;

		scanf("%d", &b);
		
		#ifdef DEBUG
		printf("mosuri %d\n", b);
		#endif
		while(b)
		{
			scanf("%d %d", &x, &y);
			graph[x+1][y+1] = connect; 
			graph[y+1][x+1] = connect; 
			#ifdef DEBUG
			printf("x,y %d,%d\n", x,y);
			printf("graph[%d][%d]=%d  graph[%d][%d]=%d\n",x+1, y+1, graph[x+1][y+1], y+1, x+1, graph[y+1][x+1]);
			#endif 
			b--;
		}
		for(i=0;i<=num;i++)
		{
			vcolor[i] = 0;
		}	
		m_coloring(0);
		
		if(result == 1)
		{
			printf("BICOLORABLE\n");
		}
		else
		{	
			printf("NOT BICOLORABLE\n");
		}
		connect++;
		result = 0;
		a--;
	}
	return 0;
}

