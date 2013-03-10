#include <stdio.h>

char wordBoard[50][50];
char word[50][50];

void initArray(void);
void check(int low, int col, int numWord);

int main(void){
	int testcase;
	scanf("%d", &testcase);
	for(int i=0 ; i<testcase ; i++){
		char blank;
		int low, col;
		initArray();
		//scanf("%c", &blank);
		scanf("%d %d", &low, &col);
		for(int j=0 ; j<low ; j++){
			scanf("%s", wordBoard[j]);
		}
		int numWord;
		scanf("%d", &numWord);
		for(int j=0 ; j<numWord ; j++){
			scanf("%s", word[j]);
		}
		check(low, col, numWord);
	}

	return 0;
}

void initArray(void){
	for(int i=0 ; i<50 ; i++)
		for(int j=0 ; j<50 ; j++){
			wordBoard[i][j] = 0;
			word[i][j] = 0;
		}
}

void check(int low, int col, int numWord){
	for(int i=0 ; i<low ; i++){
//		printf("%s", wordBoard[i]);
//		printf("\n");
	}
	//printf("%s", 
	

}
