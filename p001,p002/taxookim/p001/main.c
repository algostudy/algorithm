#include <stdio.h>

#define MAX_LIMIT 1000000
#define MIN_LIMIT 0
#define LIST_SIZE 10000

#define DEBUG 0 

int tmp_list[LIST_SIZE] = {1,};
int max_list[LIST_SIZE] = {1,};

int worst_algo(int input1, int input2);
int good_algo(int input1, int input2);

int main(void) {

  int i = 0;
  int input1, input2;
  int output = 0;

  int cnt = 0, num = 0;
  int eof = 0;
  while(1) {
    // get 2 number
    eof = scanf("%d %d", &input1, &input2);
    
    // finish conditions
    if((input1 >= MAX_LIMIT) || (input1 <= MIN_LIMIT) ||
       (input2 >= MAX_LIMIT) || (input2 <= MIN_LIMIT) ||
       (input1 > input2) || (eof != 2)) {
      return 0;
    }

    // algorithm
//    output = worst_algo(input1, input2);
    output = good_algo(input1, input2);
    // print outputs
    printf("%d %d %d\n", input1, input2, output);
  }

  return 0;
}

int worst_algo(int input1, int input2) {
  int num = 0, i = 0, cnt = 0;
  int max_cnt = 0;
  for(i = input1 ; i < (input2+1) ; i++) {
    num = i;                                                                                                                             
    cnt = 0;
    if(DEBUG) printf("%d -> ", num);
    while(num != 1) {
      if((num % 2) == 0)
        num /= 2;
      else
        num = (num * 3) + 1;

      if(DEBUG) printf("%4d", num);
      cnt++;                                                                                                                             
    }
    cnt++;                                                                                                                               
    
    if(cnt > max_cnt) {
      max_cnt = cnt;
    }
  }
  
  return max_cnt;
}

int good_algo(int input1, int input2) {
  int num = 0, i = 0, cnt = 0;
  int max_cnt = 0;
  int j = 0;
  int finish = 0;

  for(i = input1 ; i < (input2+1) ; i++) {
    num = i;                                                                                                                                                            
    cnt = 0;
    finish = 0;
    if(DEBUG) printf("%d -> ", num);
    while(num != 1) {
      tmp_list[cnt] = num;
      for(j = 0 ; j < max_cnt ; j++) {
        if(max_list[j] == num) {
          cnt += (max_cnt - j- 1);
          finish = 1;
        }
      }
      if(finish) break;
      if((num % 2) == 0)
        num /= 2;
      else
        num = (num * 3) + 1;
                                                                                                                                                                        
      if(DEBUG) printf("%4d", num);
      cnt++;                                                                                                                                                            
    }
    cnt++;
    if(DEBUG) printf("(%d)\n", cnt);  
    if(cnt > max_cnt) {
      max_cnt = cnt;
      for(j = 0 ; j < cnt ; j++)
        max_list[j] = tmp_list[j];
    }
  }  

  return max_cnt;
}
