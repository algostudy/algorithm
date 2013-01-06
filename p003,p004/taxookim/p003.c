#include <stdio.h>

int main(void) {
	int i = 0;
	int input_num = 0;
	unsigned char new_char[26] = {'A','V','X','S','W','D','F','G','U','H','J','K','N','B','I','O','Q','E','A','R','Y','C','Q','Z','T','Z'};
	unsigned char new_num[10] = {'9','1','1','2','3','4','5','6','7','8'};
	unsigned char in_char=0;
	while(scanf("%c", &in_char) > 0){
		if((in_char >= 'A')&&(in_char <= 'Z'))
			printf("%c", new_char[in_char-'A']);
		else if((in_char >= '0') && (in_char <= '9'))
			printf("%c", new_num[in_char-'0']);
		else if(in_char == '-')
			printf("0");
		else if(in_char == '<')
			printf("M");
		else if(in_char == ':')
			printf("L");
		else if(in_char == ',')
			printf("M");
		else if(in_char == '{')
			printf("P");
		else
			printf("%c", in_char);
	}

	return 0;
}
