#include <stdio.h>

int main(void)
{
  int step = 1;
  int seq = 1;
  int x = 1;
  int y = 1;
  int convert = 0;

  for(int i = 1; i < 4; i++)
  {
    printf("step : %d\n",step);
    for(int j = 0; j < 2*i-1; j++){
      printf(" - seq=%d ",seq);
      
      //좌표로직
      if(x < step && y < step){
        if(x<y) y++;
        else x++;
      }else if(y < step){
         y++;printf("y++");
      }else if(x < step){
         x++;printf("x++");
      }else{

        if(x==y && x != 1 && y != 1){
          if(step%2 == 0){
            y--;printf("y--");
          }else{
            x--;printf("x--");
          }
        }
      }

      printf("x=%d,y=%d\n",x,y);

      seq++;
    }
    printf("\n");
    convert = (!convert);
    step++;
  }      
}
