#include <iostream>

using namespace std;

int main()
{
 int i, j, n, max, sum;
 
 while(1){
 
 cin >> i >> j;

 if( i==0 || j==0)
 break;
 
 max=0;

 for(int k=i; k<j; k++)
 {
 n=k;sum=1;
 while(n!=1){

 if(n%2==0)
 n= n/2;
 else
 n = 3*n+1;
 sum++;
 }

 if(max < sum)
 max = sum;
 }
 printf("%d %d %d\n", i, j, max);
 }

 return 0;
}
