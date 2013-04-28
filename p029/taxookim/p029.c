#include <stdio.h>

#define MAX 100000

int A[MAX];// = { 8, 9, 2, 5, 7, 10 };
int cntT;

void QuickSort(int left, int right){
	int rightTemp = right + 1;
	int leftTemp = left;
	int pivot = left;

	if( right - left <= 0)
		return; 

	while ( leftTemp < rightTemp ) {
		while(A[++leftTemp] < A[pivot]) ;
		while(A[--rightTemp] > A[pivot]) ;
//		printf("%d %d \n", leftTemp, rightTemp);
		if(leftTemp >= rightTemp)
			break;
		int temp = A[leftTemp];
		A[leftTemp] = A[rightTemp];
		A[rightTemp] = temp;
	}
	int temp = A[rightTemp];
	A[rightTemp] = A[pivot];
	A[pivot] = temp;

	QuickSort(0, rightTemp-1);
	QuickSort(rightTemp+1, right);
}

int main(void){
	int testNum;
	int cnt, cntTemp;
#if 0
	QuickSort(0, 5);
	for ( int i = 0; i < 6; i++ )
		printf("%d ", A[i]);
#endif
	scanf("%d", &testNum);
	while(testNum--){
		scanf("%d", &cnt);
		cntTemp = cnt;
		cntT = cnt;
		int i=0;
		while(cntTemp--){
			scanf("%d", &A[i]);
			i++;
		}
#if 0
		i=0;
		while(i <= cnt){
			printf("%d ", A[i++]);
		}
#endif
		QuickSort(0,cnt-1);
		cntTemp = cnt;
		i = 0;
		while(cntTemp--){
			printf("%d ",A[i++]);
		}
		printf("\n");
	}

	return 0;
}
