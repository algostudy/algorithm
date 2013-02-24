#include <iostream> 
 
using namespace std; 
 
void full(int i, int j, char **arr, int n, int m) 
{ 
 if(i-1 >=0 && arr[i-1][j]!='*') 
 arr[i-1][j]++; 
 if(j-1 >=0 && arr[i][j-1]!='*') 
 arr[i][j-1]++; 
 if(i-1 >=0 && j-1>=0 && arr[i-1][j-1]!='*') 
 arr[i-1][j-1]++; 
 if(i+1<n && arr[i+1][j]!='*') 
 arr[i+1][j]++; 
 if(j+1<m && arr[i][j+1]!='*') 
 arr[i][j+1]++; 
 if(i+1 <n && j+1<m && arr[i+1][j+1]!='*') 
 arr[i+1][j+1]++; 
 if(i-1 >=0 && j+1<m && arr[i-1][j+1]!='*') 
 arr[i-1][j+1]++; 
 if(i+1 <n && j-1>=0 && arr[i+1][j-1]!='*') 
 arr[i+1][j-1]++; 
} 
 
int main() 
{ 
 int n, m, i, j, t=0; 
 char **arr; 
 
 while(1){ 
 cin >> n >> m; 
 
 if(n==0 && m==0) 
 break; 
 arr = new char* [n]; 
 for(i=0; i<n; i++) 
 arr[i] = new char [m]; 
 
 for(i=0; i<n; i++) 
 { 
 for(j=0; j<m; j++) 
 { 
 cin >> arr[i][j]; 
 if(arr[i][j]!='*') 
 arr[i][j]=0; 
 } 
 } 
 
 for(i=0; i<n; i++) 
 { 
 for(j=0; j<m; j++) 
 { 
 if(arr[i][j] == '*') 
 full(i, j, arr, n, m); 
 } 
 } 
 cout << "Field #" << ++t << ":" << endl; 
 for(i=0; i<n; i++) 
 { 
 for(j=0; j<m; j++) 
 { 
 if(arr[i][j]!='*') 
 cout << (int)arr[i][j]; 
 else 
 cout << arr[i][j]; 
 } 
 cout<< endl; 
 } 
cout << endl;
 
 for(i=0; i<n; i++) 
 delete [] arr[i]; 
 
 delete [] arr; 
 
 } 
 return 0; 
 
}
