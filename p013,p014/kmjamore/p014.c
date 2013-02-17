#include <stdio.h>
#include <math.h>
float fn_move_len(float x, float y, float xx,float yy)
{
  return sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
}
float ccw(float ax,float ay,float bx,float by,float cx,float cy)
{//0.일직선 -.오른쪽/시계방향 +.왼쪽/반시계방향
  return ax*by+bx*cy+cx*ay-ay*bx-by*cx-cy*ax;
}
int main()
{
  int case_num,stu_num;
  float cur_posX,cur_posY;
  float move_len=2;

  scanf("%d",&case_num);

  for(int t = 0; t < case_num; t++)
  {
    cur_posX = 0.0f;
    cur_posY = 0.0f;
    scanf("%d",&stu_num);

    //n명의 신입생 좌표
    float stu_posX[stu_num],stu_posY[stu_num];
    for(int i = 0; i < stu_num; i++)
    {
      scanf("%f %f",&stu_posX[i],&stu_posY[i]);
    }

    //y가 제일 작은 순으로 재배열
    for(int q = 0; q < stu_num;q++)
    for(int w = q; w < stu_num;w++)
    if(stu_posY[q] > stu_posY[w])
    {
      float temp = stu_posY[q];
      stu_posY[q] = stu_posY[w];
      stu_posY[w] = temp;
      temp = stu_posX[q];
      stu_posX[q] = stu_posX[w];
      stu_posX[w] = temp;
    }

    int k = 0;
    for(int j = 1; j <= stu_num; j++)
    {
      float res = ccw(cur_posX,cur_posY
                     ,stu_posX[k],stu_posY[k]
                     ,stu_posX[j],stu_posY[j]);
      if(res > 0)
      {
        move_len += fn_move_len(cur_posX,cur_posY,stu_posX[k],stu_posY[k]);
        cur_posX = stu_posX[k];
        cur_posY = stu_posY[k];
        k = j;
      }else if(res < 0)
      {
        move_len += fn_move_len(cur_posX,cur_posY,stu_posX[j],stu_posY[j]);
        cur_posX = stu_posX[j];
        cur_posY = stu_posY[j];
      }
    }
    //시작점으로 다시 돌아간다
    move_len += (fn_move_len(cur_posX,cur_posY,0,0));
    printf("%.2f\n",move_len);
    move_len = 0;
    if(t != (case_num-1))
      printf("\n");
  }
  return 0;
}
