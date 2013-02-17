#include <stdio.h>

unsigned long factorial(int f)
{
 unsigned long int fact = 1;
 int i;

 if ( f == 0 || f == 1 )
 return 1;
 for ( i = 2; i <= f; i ++ )
 {
 fact *= i;
 }
 return fact;
}

unsigned long int cal_Fact(int a, int b, int c)
{
 int sum = a + b + c;
 unsigned long int mom = 1;
 unsigned long int son = 1;
 int i;

 if ( (a == 0 && b == 0) || (b == 0 && c == 0) || (c == 0 && a == 0) )
 {
 return 1;
 }

 if ( (a >= b) && (a >= c) )
 {
 for (i = a+1; i <= sum; i++)
 mom *= i;
 
 son *= factorial(b);
 son *= factorial(c);
 }
 else if ( (b >= a) && (b >= c) )
 {
 for (i = b+1; i <= sum; i++)
 mom *= i;

 son *= factorial(a);
 son *= factorial(c);
 }
 else
 {
 for (i = c+1; i <= sum; i++)
 mom *= i;

 son *= factorial(a);
 son *= factorial(b);
 }

 return (unsigned long int)(mom/son); 
}

unsigned long int cal_Count(int num)
{
 unsigned long int count = 0;
 int a, b, c;

 for ( a = 0; 5*a <= num ; a++ )
 {
 for ( b = 0; (5*a) + (3*b) <= num ; b++ )
 {
 for ( c = 0; (5*a) + (3*b) + (2*c) <= num; c++ )
 {
 if ( (5*a) + (3*b) + (2*c) == num )
 {
 count += cal_Fact(a, b, c);
 }
 }
 }
 }

 return count;
}

int main()
{
 int number; // user input(stair number)
 unsigned long int count; // case number

 unsigned long int a;

 //printf("%d\n", sizeof(a));

 scanf("%d", &number);
 while ( number != 0 )
 {
 count = cal_Count(number);
 printf("%ld\n", count);
 scanf("%d", &number);
 }

 return 0;
}
