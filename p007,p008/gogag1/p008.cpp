#include <iostream>

using namespace std;

#define EMPTY 0
#define CHECKED 1
#define EXIST 2
#define NOT 4

typedef struct Data{
 int i;
 int j;
 int state;
}data;

class stack{
public:
 stack();
 void push(int i, int j, int state);//return value : state
 data pop(); //return value : data
 int stateOfTop(); // return value : state
 bool emptyOfStack(); 

private:
 int top;
 data v[1024];
};

stack::stack()
{
 top=-1;
}

void stack::push(int i, int j, int state)
{
 v[++top].i = i;
 v[top].j = j;
 v[top].state = state;
}

data stack::pop()
{ 
 return v[top--];
}

int stack::stateOfTop()
{
 return v[top].state;
}

bool stack::emptyOfStack()
{
 return (top==-1)?true:false;
}

bool isEmpty(int **pChess, int i, int j)
{
 return (pChess[i][j]==EMPTY)?true:false;
}

int numOfEmpty(int **pChess, int n)
{
 int i=0, j=0, sum=0;

 for(i=0;i<n; i++){
 for(j=0;j<n; j++){
 if(isEmpty(pChess,i,j))
 sum++;
 }
 }
 return sum;
}

void fullNotData(int i, int j, int n, int **pChess, stack *st)
{
 int num=4, l=i,m=j, a=0, b=0;

 while(num--)
 { 
 switch(num)
 {
 case 3:
 a=-1,b=-1;break;
 case 2:
 a=-1,b=1;break;
 case 1:
 a=1,b=-1;break;
 case 0:
 a=1,b=1;break;
 }

 l+=a; m+=b;

 while((l>=0 && l<n) && (m>=0 && m<n))
 {
 if(pChess[l][m]!=NOT && pChess[l][m]!=CHECKED){
 pChess[l][m]=NOT;
 (*st).push(l,m,NOT); 
 }
 l+=a; m+=b;
 }

 l=i,m=j;
 }
}

void removeDataOfStack(int *i, int *j, int **pChess, stack *st)
{
 data temp;

 while((*st).stateOfTop()!=EXIST)
 {
 temp = (*st).pop();
 pChess[temp.i][temp.j]=EMPTY;
 }

 temp = (*st).pop();
 *i=temp.i; *j=temp.j;
 pChess[*i][*j]=CHECKED;
 (*st).push(*i,*j,CHECKED);
}
int main()
{
 int n=0, k=0, i=0, j=0, sum=0;
 bool ret=false;


 while(1){

 sum=0;n=0;k=0;
 stack st;ret=false;

 cin >> n;
 cin >> k;

 if(n==0 || k==0)
 break;

 int **pChess = new int*[n];
 for(i=0; i<n; i++)
 pChess[i] = new int[n];

 for(i=0; i<n; i++)
 for(j=0; j<n; j++)
 pChess[i][j] = EMPTY;

 int chess = k-1;

 for(i=0; i<n; i++)
 {
 if(k==1){
 sum = n*n;
 break;
 }
 for(j=0; j<n; j++)
 {
 if(chess>0){
 if(k>numOfEmpty(pChess, n) && chess>=numOfEmpty(pChess, n))
 {
 removeDataOfStack(&i, &j, pChess, &st);
 chess++;
 if(k>=(n*n -(n*i+j)) && chess==k-1){
 ret=true;
 break;
 }
 continue;
 }
if(isEmpty(pChess,i,j)){
 pChess[i][j]=EXIST;
 st.push(i,j,EXIST); 
 fullNotData(i, j, n, pChess, &st);
 chess--; 
 }
 }else{
 sum += numOfEmpty(pChess, n);
 removeDataOfStack(&i, &j, pChess, &st);
 chess++;
 }
 }
 if(ret)
 break;
 }

 printf("%d", sum);
 
 for(i=0; i<n; i++)
 delete pChess[i];
 delete pChess;
 }

 return 0;
}
