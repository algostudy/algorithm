#include <stdio.h>
#include <string.h>

int main(void){
	int numTestCase;
	scanf("%d", &numTestCase);
	for(int i=0 ; i<numTestCase ; i++){
		int numFriends;
		int numFoods;
		String str;
		String friends[50] = {'\0',};
		int numLike[50] = {0,};
		String who[50][50] = {'\0',};

		scanf("%d %d", &numFriends, &numFoods);
		scanf("%s", &str);
		int id = 0;
		for(int i=0 ; *(str+i)!='\0' ; i++){
			if( (*(str+i)>='a') && (*(str+i)<='z')){
				friends[id] = *(str+i);
			}
		}
		
		for(int i=0 ; i<numFoods ; i++){
			scanf("%d", numLike[i]);
			for(int j=0 ; j<numLike[i] ; j++){
				
	}
}
