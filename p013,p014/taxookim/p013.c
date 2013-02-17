#include <stdio.h>
#include <math.h>

float hole_xy[1000][2];

void check(int, float, float, float, float);

int main(void){
	int cnt_hole;
	float gopher_x, gopher_y, dog_x, dog_y;
	int i;
	
	while(scanf("%d %f %f %f %f",&cnt_hole, &gopher_x, &gopher_y, &dog_x, &dog_y)){
		if(cnt_hole == 0){
			return -1;
		}
		for(i=0 ; i<cnt_hole ; i++){
			scanf("%f %f", &hole_xy[i][0], &hole_xy[i][1]);
		}
		check(cnt_hole, gopher_x, gopher_y, dog_x, dog_y);
	}
	return 0;
}

void check(int cnt_hole, float gx, float gy, float dx, float dy){
	int i;
	float dist_gopher, dist_dog;
	for(i=0 ; i<cnt_hole ; i++){
		dist_gopher = (hole_xy[i][0]-gx)*(hole_xy[i][0]-gx) + (hole_xy[i][1]-gy)*(hole_xy[i][1]-gy);
		dist_dog = (hole_xy[i][0]-dx)*(hole_xy[i][0]-dx) + (hole_xy[i][1]-dy)*(hole_xy[i][1]-dy);
		if(dist_gopher*4 > dist_dog){
//			printf("The gopher cannot escape.\n");
		}else{
			printf("The gopher can escape through the hole at (%f,%f).\n",hole_xy[i][0], hole_xy[i][1]);
			return;
		}
	}
	printf("The gopher cannot escape.\n");
}
