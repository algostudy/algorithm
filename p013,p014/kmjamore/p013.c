#include <stdio.h>
#include <math.h>

int main()
{
  int hole_num,escape;
  float daramX,daramY,dogX,dogY,holeX,holeY;

  while(scanf("%d %f %f %f %f",&hole_num,&daramX,&daramY,&dogX,&dogY) == 5){

    float holeArrX[hole_num];
    float holeArrY[hole_num];
    escape = -1;

    for(int i = 0; i<hole_num; i++)
    {
      scanf("%f %f",&holeArrX[i],&holeArrY[i]);
    }

    for(int j = 0; j<hole_num; j++)
    {
      holeX = holeArrX[j];
      holeY = holeArrY[j];

      //구멍으로부터 각자의 거리 계산
      float hole_to_daram = sqrt((holeX-daramX)*(holeX-daramX)+(holeY-daramY)*(holeY-daramY));
      float hole_to_dog = sqrt((holeX-dogX)*(holeX-dogX)+(holeY-dogY)*(holeY-dogY));

      //시간=거리/속도
      if(hole_to_daram/1 < hole_to_dog/2)
      {
        escape = j;
        break;
      }
    }
  
    if(escape < 0)
    {
      printf("The gopher cannot escape.\n");
    }else{
      printf("The gopher can escape through the hole at (%.3f,%.3f).\n",holeX,holeY);
    }
  }

  return 0;
}

