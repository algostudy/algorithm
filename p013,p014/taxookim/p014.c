#include <stdio.h>
#include <math.h>

float stu[1000][2];

void calc(int cnt);
bool isInside(float x1, float y1, float x2, float y2, float p1, float p2);

int main (void){
	int case_cnt;
	int xy_cnt, i, j;

	scanf("%d", &case_cnt);
	scanf("");
	for(i=0 ; i<case_cnt ; i++){
		scanf("%d", &xy_cnt);
		for(j=0 ; j<xy_cnt ; j++){
			scanf("%f %f", &stu[j][0], &stu[j][1]);
		}
		calc(xy_cnt);
		printf("\n");
	}

}

void calc(int cnt){
	int i, x_max, x_min, y_max, y_min;
	int xmaxtmp=0, xmintmp=0, ymaxtmp=0, ymintmp=0;
	float angle_dist_outer[1000][3] = {0,};
	float total_dist = 2;

	//init
	for(i=0 ; i<cnt ; i++){
		angle_dist_outer[i][0] = stu[i][1] / stu[i][0];
		if(stu[i][0] > xmaxtmp){
			x_max = i;
			xmaxtmp = stu[i][0];
		}else if(stu[i][0] < xmintmp){
			x_min = i;
			xmintmp = stu[i][0];
		}else{
		}

		if(stu[i][1] > ymaxtmp){
			y_max = i;
			ymaxtmp = stu[i][1];
		}else if(stu[i][1] < ymintmp){
			y_min = i;
			ymintmp = stu[i][1];
		}else{
		}
		
	}

	




}

bool isInside(float x1, float y1, float x2, float y2, float p1, float p2){
	bool zerois;


}

