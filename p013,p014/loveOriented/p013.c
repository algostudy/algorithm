#include <stdio.h>
#include <math.h>

#define MAX 1000

typedef struct position_t
{
	float x;
	float y;
}position_t;

position_t gopher;
position_t dog;
position_t hole[MAX];

int main(void)
{
	int a,b,c;
	int i,j;
	while(scanf("%d", &a) == 1)
	{
		int can_gopher_escape = 0;	
		scanf("%f", &gopher.x);
		scanf("%f", &gopher.y);
		scanf("%f", &dog.x);
		scanf("%f", &dog.y);
	
		//printf("%d %f %f %f %f\n", a, gopher_pos_x, gopher_pos_y, dog_pos_x, dog_pos_y);
		for(i=0; i<a; i++)
		{
			float dist_dog;
			float dist_gopher;
			scanf("%f", &hole[i].x);
			scanf("%f", &hole[i].y);
			//printf("[%d] %f %f\n", i, hole[i].x, hole[i].y);

			if(can_gopher_escape == 1)
			{
				continue;
			}
			//calculate the distance
			dist_dog = pow((hole[i].x - dog.x), 2) + pow((hole[i].y - dog.y), 2);
			dist_dog = sqrt(dist_dog);
			//printf("dist_dog : %f\n", dist_dog);
			dist_gopher = pow((hole[i].x - gopher.x), 2) + pow((hole[i].y - gopher.y), 2);
			dist_gopher = sqrt(dist_gopher);
			dist_gopher*= 2;
			//printf("dist_gopher : %f\n", dist_gopher);
			
			if(dist_gopher < dist_dog)
			{
				printf("The gopher can escape through the hole at (%.3f,%.3f).\n",hole[i].x, hole[i].y);
				can_gopher_escape = 1;			
			}
		}

		if(can_gopher_escape != 1)
		{
			printf("The gopher cannot escape.\n");
		}
	}
	return 0;
}
