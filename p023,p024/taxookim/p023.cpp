#include <stdio.h>

int main(void){
	int numTestCase;
	scanf("%d\n", &numTestCase);
	int startNumber[4];
	int target[4];
	int numBlock;
	for(int i=0 ; i<numTestCase ; i++){
		scanf("%d %d %d %d\n", &startNumber[0], &startNumber[1], &startNumber[2], &startNumber[3]);
		scanf("%d %d %d %d\n", &target[0], &target[1], &target[2], &target[3]);
		scanf("%d", &numBlock);
#if 1
		int blockList[numBlock][4];
		for(int j=0 ; j<numBlock ; j++){
			scanf("%d %d %d %d\n", &blockList[j][0], &blockList[j][1], &blockList[j][2], &blockList[j][3]);
		}
#endif
#if 1
		printf("%d %d %d %d\n", startNumber[0], startNumber[1], startNumber[2], startNumber[3]);
		printf("%d %d %d %d\n", target[0], target[1], target[2], target[3]);
		printf("%d\n", numBlock);
		for(int j=0 ; j<numBlock ; j++){
			printf("%d %d %d %d\n", blockList[j][0], blockList[j][1], blockList[j][2], blockList[j][3]);
		}
	
#endif
	}

}
