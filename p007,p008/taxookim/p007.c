#include <stdio.h>

int contDivisor(unsigned int);

int main(void){
	unsigned int input;
	while(1){
		scanf("%d",&input);
		if(input == 0) break;
		else{
			if(countDivisor(input)) printf("yes\n");
			else		printf("no\n");
		}
	}
	return 0;
}

/*
int countDivisor(unsigned int input){
	int cnt=2; //count 1 and input number
	unsigned int i;
	unsigned int limit = input;
	if(input >= 4){
		for(i=2 ; i < limit ; i++){
			limit = input/i;
			if((input%i)==0){
				cnt += 2;
//				limit = input/i;
//				printf("%d ",i);
				if(i == limit) cnt--;
			}
		}
	}else if(input == 1){ cnt = 1;
	}else if(input == 2){ cnt = 2;
	}else if(input == 3){ cnt = 2;
	}else               { cnt = 0;
	}
//	printf("  -> %d",cnt);
	return cnt;
}
*/
/*
int countDivisor(unsigned int input){
	unsigned int i, limit;
	if(input>=4){
		for(i=2 ; i<limit ; i++){
			limit = input / i;
			if((i == limit) && (i*limit == input))
				return 1;
		}
		return 0;
	}else if(input == 1){
		return 1;
	}else if((input==2)||(input==3)){
		return 0;
	}else{
		return 0;
	}
	return 0;
}
*/


int countDivisor(unsigned int input){
	unsigned int i=0, limit=0;
	unsigned int point=0x1;
	unsigned int backup_input = input;
	unsigned int j;
	for(j=31 ; j>0 ; j--){
		if(backup_input & (point<<j)){
			j = j>>1;
			if(j==0) break;
//printf("j>>1 = %d\n",j);
			i += (0x1 << j);
//printf("i+=  = %d\n",i);
			backup_input = backup_input >> j;
//printf("ba_in= %d\n",backup_input);
		}
	}
//	printf("%d : 0x%8X\n",i, i);
	for( ; limit < input ; i++){
		limit = i * i;
		if(limit == input){
			return 1;
		}
	}
	return 0;
}


/*
int countDivisor(unsigned int input){
        unsigned int i=1, limit=0;
        unsigned int point=0x1;
        unsigned int j;
        for(j=31 ; point != 0 ; j--){
                if(input & (point<<j)){
                        i = 0x01<<(j>>1);
                        point = 0;
                }
        }
        for( ; limit < input ; i++){
                limit = i * i;                                                                                                                                                                       
                if(limit == input)
                        return 1;
        }
        return 0;
}
*/














