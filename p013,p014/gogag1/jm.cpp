#include "stdio.h" 
//#define DEBUG 1 
//#define DEBUG_DETAIL 1 
#define PRODUCT 1 
 
unsigned long int CheckResult(unsigned long input); 
unsigned long int CheckResult_num(unsigned long int num2, unsigned long int num3, unsigned long int num5); 
unsigned long int MulNum(unsigned long int input); 
 
int main() 
{ 
 unsigned long int result = 0; 
 unsigned long int input = 0; 
unsigned long int res[101]={0,};
	for(int i=1; i<101; i++)
		res[i]=CheckResult(i);

	while(1){
		scanf("%d", &input);
		if(input==0) 
			break;

		printf("%ld\n", res[input]); 
	}
 return 0; 
} 
 
unsigned long int CheckResult(unsigned long int input) 
{ 
 unsigned long int result = 0; 
 unsigned long int input_data = input; 
 unsigned long int num2 = 0; 
 unsigned long int num3 = 0; 
 unsigned long int num5 = 0; 
 
 unsigned long int checkInput01 = input_data / 2; 
 unsigned long int checkInput02 = input_data % 2; 
 
 if(input == 1) 
 return 0; 
 
 if(checkInput02) 
 { 
 num2 = checkInput01 - 1; 
 num3 = 1; 
 } 
 else 
 { 
 num2 = checkInput01; 
 } 
 
#ifdef DEBUG 
 printf("num2 [%d] num3 [%d] num5 [%d]\n", num2 , num3 , num5); 
#endif 
 result = result + CheckResult_num(num2, num3, num5); 
 
 while(num2 >= 0) 
 { 
 unsigned long int tempNum2 = num2; 
 unsigned long int tempNum3 = num3; 
 unsigned long int tempNum5 = num5; 
 
 while(tempNum2 > 0 && tempNum3 > 0) 
 { 
 tempNum2 = tempNum2 - 1; 
 tempNum3 = tempNum3 - 1; 
 tempNum5 = tempNum5 + 1; 
#ifdef DEBUG 
 printf("tempNum2 [%d] tempNum3 [%d] tempNum5 [%d]\n", tempNum2 , tempNum3 , tempNum5); 
#endif 
 result = result + CheckResult_num(tempNum2, tempNum3, tempNum5); 
 } 
 
 if(num2 >= 3) 
 { 
 num2 = num2 - 3; 
 num3 = num3 + 2; 
#ifdef DEBUG 
 printf("num2 [%d] num3 [%d] num5 [%d]\n", num2 , num3 , num5); 
#endif 
 result = result + CheckResult_num(num2, num3, num5); 
 } 
 else 
 { 
 break; 
 } 
 } 
 return result; 
} 
 
unsigned long int CheckResult_num(unsigned long int num2, unsigned long int num3, unsigned long int num5) 
{ 
 unsigned long int totalnum = num2 + num3 + num5; 
 unsigned long int result = 0; 
 
 unsigned long int maxNum = 0; 
 unsigned long int aboveNum = 1; 
 unsigned long int belowNum = 1; 
 unsigned long int aboveNumTemp = 1; 
 unsigned long int checkAboveNumByBelowNum = 1; 
 unsigned long int belowNumSum[50]={0,}; 
 unsigned long int indexBelowNumSum = 0; 
 
 if(num2 > num3) 
 { 
 if(num2 > num5) 
 { 
 maxNum = num2; 
 num2 = 1; 
 } 
 else 
 { 
 maxNum = num5; 
 num5 = 1; 
 } 
 } 
 else 
 { 
 if(num3 > num5) 
 { 
 maxNum = num3; 
 num3 = 1; 
 } 
 else 
 { 
 maxNum = num5; 
 num5 = 1; 
 } 
 }
#ifdef DEBUG 
	printf("totalnum [%d] maxNum [%d] num2 [%d] num3 [%d] num5 [%d]\n",totalnum,maxNum, num2 , num3 , num5); 
#endif 
 
 
 while(num2 > 1) 
 { 
 belowNumSum[indexBelowNumSum] = num2; 
 num2 = num2 - 1; 
 indexBelowNumSum = indexBelowNumSum + 1; 
 } 
 while(num3 > 1) 
 { 
 belowNumSum[indexBelowNumSum] = num3; 
 num3 = num3 - 1; 
 indexBelowNumSum = indexBelowNumSum + 1; 
 } 
 while(num5 > 1) 
 { 
 belowNumSum[indexBelowNumSum] = num5; 
 num5 = num5 - 1; 
 indexBelowNumSum = indexBelowNumSum + 1; 
 } 
#ifdef DEBUG 
 for(indexBelowNumSum = 0; indexBelowNumSum < 50; indexBelowNumSum++) 
 { 
 if(belowNumSum[indexBelowNumSum] != 0) 
 printf("belowNumSum [%d] = %d\n",indexBelowNumSum,belowNumSum[indexBelowNumSum]); 
 else 
 break; 
 } 
#endif 
 while(totalnum > maxNum) 
 { 
 aboveNum = aboveNum * totalnum; 
 totalnum = totalnum - 1; 
#ifdef DEBUG 
 printf("aboveNum [%d] totalnum [%d]\n",aboveNum,totalnum); 
#endif 
 for(indexBelowNumSum = 0; indexBelowNumSum < 50; indexBelowNumSum++) 
 { 
 if(belowNumSum[indexBelowNumSum] != 0) 
 { 
 checkAboveNumByBelowNum = aboveNum % belowNumSum[indexBelowNumSum]; 
 if(checkAboveNumByBelowNum) 
 ; 
 else 
 { 
 aboveNum = aboveNum / belowNumSum[indexBelowNumSum]; 
 belowNumSum[indexBelowNumSum] = 1; 
 } 
 } 
 else 
 break; 
 } 
 } 
#ifdef DEBUG 
 for(indexBelowNumSum = 0; indexBelowNumSum < 50; indexBelowNumSum++) 
 { 
 if(belowNumSum[indexBelowNumSum] != 0) 
 printf("2ND > belowNumSum [%d] = %d\n",indexBelowNumSum,belowNumSum[indexBelowNumSum]); 
 else 
 break; 
 } 
#endif 
/* 
 for(indexBelowNumSum = 0; indexBelowNumSum < 50; indexBelowNumSum++) 
 { 
 if(belowNumSum[indexBelowNumSum] != 0) 
 aboveNum = aboveNum / belowNumSum[indexBelowNumSum]; 
 else 
 break; 
 } 
*/ 
 result = aboveNum; 
 
// result = aboveNum / (MulNum(num2) * MulNum(num3) * MulNum(num5)); 
 
// result = MulNum(totalnum) / (MulNum(num2) * MulNum(num3) * MulNum(num5)); 
 
 
#ifdef DEBUG_DETAIL 
 printf("num2 [%d] num3 [%d] num5 [%d] totalnum [%d] / Result : [%d]\n", num2 , num3 , num5,totalnum, result); 
#endif 
 return result; 
} 
 
unsigned long int MulNum(unsigned long int input) 
{ 
 unsigned long int result = 1; 
 if(input != 0) 
 { 
 while(input > 1) 
 { 
 result = result * input; 
 input--; 
 } 
 } 
 else 
 result = 1; 
 return result; 
}
