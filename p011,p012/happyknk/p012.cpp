#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n = 0;

	while(scanf("%d", &n)){
		if(n==0) break;
		int i=(int)sqrt(n), m=i*i;
		if(m<n){
			i++;
			m=i*i;
		}

		int x, y;

		if(i%2==1){
			x=1;
			y=i;

			if(m-i+1>=n){
				m = m-i+1;
				x = i;
			}
			while(m!=n){
				if(x<i){
					x++;
				}else if(y>0){
					y--;
				}
				m--;
			}
		}else{
			x=i;
			y=1;
			if(m-i+1>=n){
				m = m-i+1;
				y = i;
			}
			while(m!=n){
				if(y<i){
					y++;
				}else if(x>0){
					x--;
				}
				m--;
			}
		}
		printf("%d %d\n", x, y);
	}

	return 0;
}
