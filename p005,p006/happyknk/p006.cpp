#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idx = 2;
char fibo[500][101];

void stringReverse(char* str){

	for(int i=0; i<(strlen(str)/2); i++){
		char temp = str[i];
		str[i] = str[strlen(str)-1-i];
		str[strlen(str)-1-i] = temp;
	}
}

void fibonacci(){

	char a[101]={'\0',};
	char b[101]={'\0',};

	a[0] = '1';
	b[0] = '2';
	strcpy(fibo[0], a);
	strcpy(fibo[1], b);

	while(1){

		int carry = 0;
		int b_len = strlen(b);
		for(int i=0; i<b_len; i++){
			int temp = 0;
			if(a[i]=='\0'){
				temp = (b[i]-48) + carry;
			}else{
				temp = (b[i]-48) + (a[i]-48) + carry;
			}
			
			carry = (temp>9)?1:0;
			if(carry==1&&i+1>100){ idx--; return; }
			fibo[idx][i] = ((temp>9)?(temp%10):temp)+48;
			if(carry==1&&i==(b_len-1))
				fibo[idx][i+1] = 49;
		}
		fibo[idx][b_len + carry] = '\0';
		strcpy(a, b);
		strcpy(b, fibo[idx]);
		stringReverse(fibo[idx]);
		idx++;
	}
}

int main(){

	fibonacci();
	while(1){
		char n1[101]={'\0',};
		char n2[101]={'\0',};
		int count = 0;
		scanf("%s %s", n1, n2);
		if(atoi(n1)==0 && atoi(n2)==0) break;
		idx = -1;
		while(1){
			int len1 = strlen(fibo[++idx]);
			int len2 = strlen(n1);
			if(len1<len2) continue;
			if(len1==len2&&strcmp(fibo[idx], n1)<0) continue;
			len2 = strlen(n2);
			if(len1>len2) break;
			if(len1==len2&&strcmp(fibo[idx], n2)>0) break;
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}

