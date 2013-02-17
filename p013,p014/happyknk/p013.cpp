#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double x[1000];
double y[1000];

int main(){
	
	int n = 0;
	double gx, gy, dx, dy;
	int count = 0;
	while(count++<10000){
		scanf("%d %lf %lf %lf %lf", &n, &gx, &gy, &dx, &dy);
	
		int escape = -1;
		double a, b, r1, r2;
	
		for(int i=0; i<n; i++){
			scanf("%lf %lf", &x[i], &y[i]);
			if(escape<0){
				//a = x[i]-gx;
				//b = y[i]-gy;
				//r1 = sqrt((x[i]-gx)*(x[i]-gx)+(y[i]-gy)*(y[i]-gy));
				//a = x[i]-dx;
				//b = y[i]-dy;
				//r2 = sqrt((x[i]-dx)*(x[i]-dx)+(y[i]-dy)*(y[i]-dy));
				//r2 = sqrt(a*a+b*b);
				if((sqrt((x[i]-gx)*(x[i]-gx)+(y[i]-gy)*(y[i]-gy))*2)<sqrt((x[i]-dx)*(x[i]-dx)+(y[i]-dy)*(y[i]-dy))){
					escape = i;
				}
			}
		}

		if(escape<0){
			printf("The gopher cannot escape.\n");
		}else{
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", x[escape], y[escape]);
		}
	}

	return 0;
}
