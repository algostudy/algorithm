#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringReverse(char* str){

	for(int i=0; i<(strlen(str)/2); i++){
		char temp = str[i];
		str[i] = str[strlen(str)-1-i];
		str[strlen(str)-1-i] = temp;
	}
}

int main(){

	while(1){
		char n1[101]={'\0',};
		char n2[101]={'\0',};
		char a[101]={'\0',};
		char b[101]={'\0',};
		char c[101]={'\0',};
		int count = 0;
		scanf("%s %s", n1, n2);
		if(atoi(n1)==0 && atoi(n2)==0) break;

		a[0] = '1';
		b[0] = '2';

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
				c[i] = ((temp>9)?(temp%10):temp)+48;
				if(carry==1&&i==(b_len-1)) c[i+1] = 49;
			}
			strcpy(a, b);
			strcpy(b, c);
			int len1 = strlen(c);
			int len2 = strlen(n1);
			if(len1<len2) continue;
			//stringReverse(c);
			//if(len1==len2&&strcmp(c, n1)<=0) continue;
			if(len1==len2){
				bool flag = false;
				for(int j=0; j<len1; j++){
					if(c[len1-1-j]<n1[j]){
						flag = true;
						break;
					}else if(c[len1-1-j]>n1[j]){
						flag = false;
						break;
					}else{ flag = false; }
				}
				if(flag) continue;
			}
			len2 = strlen(n2);
			if(len1>len2) break;
			//if(len1==len2&&strcmp(c, n2)>=0) break;
			if(len1==len2){
				bool flag = false;
				for(int j=0; j<len1; j++){
					if(c[len1-1-j]>n2[j]){
						flag = true;
						break;
					}else if(c[len1-1-j]<n2[j]){
						flag = false;
						break;
					}else{ flag = false; }
				}
				if(flag) break;
			}
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}

