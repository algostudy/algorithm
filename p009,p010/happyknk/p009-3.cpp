#include <vector>
#include <list>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <string>

#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()
#define EPS 1e-9

using namespace std;

int edgeBoard[200][200];
int V[200];
int getV;
int getE;
bool result;

void markAll(int node,int color){
	if(V[node] != 0){
		if(V[node] != color){
			result = false;
			return ;
		}
	}
	else{
		V[node] = color;
		int nextColor;
		if(color == 1) nextColor = 2;
		else nextColor = 1;
		for(int i = 0 ; i < getV ; i++){
			if(edgeBoard[node][i] == 1) markAll(i,nextColor);
		}
	}
}


int main()
{

	while(1){
		memset(edgeBoard,0,sizeof(edgeBoard));
		memset(V,0,sizeof(V));
		cin>>getV;
		if(getV == 0) break;
		cin>>getE;

		int n1,n2;

		for(int i = 0 ; i < getE ; i++){
			cin>>n1>>n2;
			edgeBoard[n1][n2] = 1;
			edgeBoard[n2][n1] = 1;
		}
		result = true;
		markAll(0,1);
		if(result) cout<<"BICOLORABLE"<<endl;
		else cout<<"NOT BICOLORABLE"<<endl;

	}
	
	return 0;
}

