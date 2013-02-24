#include <stdio.h>
#include <stdlib.h>

char black[15];
char white[15];

int priority(char c){
	int re = 0;
	if( c == 'A' ){
		re = 14;
	}else if( c == 'K' ){
		re = 13;
	}else if( c == 'Q' ){
		re = 12;
	}else if( c == 'J' ){
		re = 11;
	}else{
		re = c;
	}
	return re;
}

void arrange(char *card){
		
	for(int i=0; i<15; i+=3){
		for(int j=i+1; j<15; j+=3){
			if(priority(card[i]) < priority(card[j])){
				char temp = card[i];
				card[i] = card[j];
				card[j] = temp;
				temp = card[i+1];
				card[i+1] = card[j+1];
				card[j+1] = temp;
			}
		}
	}

}

int poker(char *card){

	int grade = 1;
	int dup = 1;
	for(int i=0; i<12; i+=3){
		if(card[i]==card[i+3]+1){
			dup++;
		}else{
			if(dup<3) dup = 1;
		}
	}

	if(dup == 4){
		if(card[1]==card[4]&&card[4]==card[7]&&card[7]==card[10]&&card[10]==card[13])
			grade = 9;
		else grade = 8;
	}else if(dup == 4){
		grade = 7;
	}else if(dup == 3){
	}else if(dup == 2){
	}else{
	}


	return grade;

}

int main(){
	
	int count = 0;
	
	while(count++<10000){
		for(int i=0; i<15; i++){
			black[i] = getchar();
		}
		for(int i=0; i<15; i++){
			white[i] = getchar();
		}

		arrange(black);
		arrange(white);
		
	}



	printf("Black wins.\n");
	printf("White wins.\n");
	printf("Tie.\n");

	return 0;
}
