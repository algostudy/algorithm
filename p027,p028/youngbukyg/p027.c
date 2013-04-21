#include <stdio.h>
	
int order = 0;
int rest[20];
int next, num, decimal;



int DtoB(int de) {

	next = de / 2;
	if(de < 2) {
		rest[order] = de;
		return 0;
	}
	
	rest[order] = de % 2;	
	order++;
	DtoB(next);

}

void Print_Bi(void) {
	for(order; order>=0; order--) {
	printf("%d",rest[order]);
		rest[order] = 0;
	}
	printf("\n");


}

int main(void) {
	//take input
	scanf("%d", &num);
	for(int i=0; i<num; i++){	
		scanf("%d", &decimal);
		DtoB(decimal);
		Print_Bi();	
		order = 0;
	}	

	return 0;
}

