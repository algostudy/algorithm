#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double x[1000];
double y[1000];
double m[1000];

int main(){
	
	int count = 0, n = 0;

	scanf("%d", &count);
	scanf("%d", &n);
	
	double x, y;
	for(int i=0; i<n; i++){
		scanf("%lf %lf", &x[i], &y[i]);
		m[i] = sqrt(x*x+y*y);
	}

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n j++){
			if(m[i]<m[j]){
				double temp = m[i];
				m[i] = m[j];
				m[j] = temp;
				temp = x[i];
				x[i] = x[j];
				x[j] = x[i];
				temp = y[i];
				y[i] = y[j];
				y[j] = temp;
			}
		}
	}


	

	printf("%d\n", x);

	return 0;
}
