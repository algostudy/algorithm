#include <stdio.h>
#include <stdlib.h>

int graph[200][200];
int color[200];
int n=0;
int l=0;

int q[10000000];


void coloring(){
	int front=0, rear=0;
	int clr = 1;
	int i=0;
	q[rear++] = 0;
	color[0] = 1;
	while(rear!=front){
		i = q[front++];
		for(int m=0; m<l; m++){
			if(graph[i][m]==1){
				if(color[m]==0){
					color[m] = color[i]==1?2:1;
					q[rear++] = m;
				}else{
					if(color[m]==color[i]){
						printf("NOT BICOLORABLE\n");
						return;
					}
				}
			}
		}
	}

	printf("BICOLORABLE\n");

}

int main(){

	while(scanf("%d", &n)){
		if(n==0) break;
		scanf("%d", &l);
	
		for(int a=0; a<n; a++){
			for(int b=0; b<n; b++){
				graph[a][b]=0;
			}
		}
	
		for(int a=0; a<n; a++){
			color[a] = 0;
		}

		for(int i=0; i<l; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x][y] = 1;
			graph[y][x] = 1;
		}
		coloring();
	}

	return 0;
}

