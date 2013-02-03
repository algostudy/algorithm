#include <stdio.h>

#define MAXN 200

static int n, graph[MAXN][MAXN]; 
static int color[MAXN]; //color[i] = i번째 정점의 색 
static int colorable; //bicoloring 가능 여부

int input()
{
 int i,j,l,a,b;
 scanf("%d",&n); 
 if(n==0)  
  return 0;
 //그래프 초기화 
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   graph[i][j]=0;

 scanf("%d",&l);
 for(i=0;i<l;i++)
 {
  scanf("%d %d",&a,&b);
  graph[a][b]=graph[b][a]=1; //무방향그래프이기 때문
 }
 return 1;
}

void dfs(int node,int c)
{
 int i;
 color[node] = c; //node의 색은 c로 지정 
 for(i=0;i<n&&colorable;i++)
 {
  if(graph[node][i] == 0) //node와 i가 연결되어 있지 않을 때 
   continue;

  if(color[i] == 0)
   dfs(i,c%2+1); //i번째 노드를 중심으로 다시 순회 
  else
  {
   if(color[i] == c) // 색이 같을 때 
   {
    colorable = 0; //bicoloring 불가능 
    return; 
   }
  }
 }
}

void main(void)
{
 int i;

 while(input())
 {
  for(i=0;i<n;i++)
   color[i] = 0;
  colorable = 1;
  dfs(0,1);

  if(colorable == 0)
   printf("NOT BICOLORABLE\n");
  else
   printf("BICOLORABLE\n");
 }
}
