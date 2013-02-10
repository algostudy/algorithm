#include <stdio.h>
static unsigned long factorial(int n){
  int i = 1;
  unsigned long result = 1;
  for(i=1;i<=n;i++){
    result = result*i;
  }
  return result;
}
int main(void){

  int i,j,p,input_val,valueKind;
  unsigned long cnt;

  while(scanf("%d",&input_val) == 1 && input_val != 0){
  
    cnt = 0;
    valueKind = 0;

    for(i = 0; i<20; i++){
      for(j = 0; j<33;j++){
        for(p = 0; p<50;p++){
          if(5*i+3*j+2*p == input_val){
            valueKind = (i+j+p);
            cnt += (factorial(valueKind)/(factorial(i)*factorial(j)*factorial(p)));
          }
        }
      }
    }
    printf("%ld\n", cnt); fflush(stdout);
  }

  return 0;
}
