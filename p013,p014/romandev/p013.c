#include <stdio.h>
#include <math.h>

typedef struct
{
	float x;
	float y;
} coordinate;

inline static float
powpow(coordinate* a_position1, coordinate* a_position2)
{
	float x_vector = a_position2->x - a_position1->x;
	float y_vector = a_position2->y - a_position1->y;

	return x_vector * x_vector + y_vector * y_vector;
}

int main(void)
{
	int        n;
	coordinate dog;
	coordinate gopher;
	coordinate hole;
	coordinate result;
	int        flag = 1;

	while ( scanf("%d %f %f %f %f", &n, &dog.x, &dog.y, &gopher.x, &gopher.y) == 5 )
	{
		flag = 1;
		for ( int i = 0; i < n; i++ )
		{
			scanf("%f %f", &hole.x, &hole.y);
			if ( flag )
			{
				float dog_distance = powpow(&hole, &dog) * 4;
				float gopher_distance = powpow(&hole, &gopher);

				if ( dog_distance < gopher_distance )
				{
					flag = 0;
					result = hole;
				}
			}
		}

		switch ( flag )
		{
		case 0:
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", result.x, result.y);
			break;
		case 1:
			printf("The gopher cannot escape.\n");
		}
	}

	return 0;
}
