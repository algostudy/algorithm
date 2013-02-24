#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  int groundX,groundY; //X는 세로수, Y는 가로수
  int q,z,i,j;
  while( scanf("%d %d",&groundX,&groundY) == 2 )
  {   
    if(groundX == 0 && groundY == 0)
     break;

    char ground[groundX][groundY];
    for(q=0;q<groundX;q++)
      scanf("%c",&ground[q]);
  



  }
  for(i=0;i<groundX;i++)
    for(j=0;j<groundY;j++)
      printf("%c",ground[i][j]);
  return 0;
}
