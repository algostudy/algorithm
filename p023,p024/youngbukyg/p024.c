#include <stdio.h>

int main(void) {

	int total;
	scanf("%d", &total);
for(int i=0 ; i<total ; i++){
	//variables	
	int input; 	//to deal input
	int count = 0; 	//for count
	int pal;	//for palindrome	
	int num[10];	//variable to parse intputs to arrangement
	int revert[10];	//variablei to revert num[]
	int sum[10];	//result of sumerizing
	int loop = 0;	//count of checking
	

	//take input
	scanf("%d", &input);

	//initailizing of num
	for(int i=0;i<10;i++) {
		num[i] = 0;
		revert[i] = 0;
		sum[i] = 0;
	}
	for(int i=0;i<10;i++) {
		num[i] = input % 10;	
		input  = input / 10;
		count++;
		if(input == 0)
			break;
	}

for(;;) {

	// num -> revert
	for(int i=0;i<count;i++){
		revert[count-1 - i] = num[i];
	}

	//sum (num + revert)
	int over=0;	//check 
	for(int i=0 ; i<count ; i++){
		sum[i] = num[i] + revert[i] + over;
		if(sum[i] > 9){
			sum[i] = sum[i] % 10;
			over = 1;
		}
		else
			over = 0;
	}
	if(over == 1){
		count++;
		sum[count-1] = 1;
	}

	int flag = 0;
	
//	3.check the result
	for(int i = 0; i<count/2 ;i ++)	
	{
		if(sum[count - 1 - i] != sum[i])
		{
			flag = -1;
			break;	
		}
		
		
	}
	loop++;
	if(flag == 0)
	{
//		printf("=================\n");
		printf("%d ",loop);
		for(int i=count - 1;i>=0;i--)
			printf("%d", sum[i]);		
		printf("\n");		
//		printf("=================\n");
		break;
	}
	else{
		for(int i=0 ; i < count ; i++){
			num[i] = sum[i];
		}
	}

}	
//end progress
}
//	printf("end p019\n");
	return 0;
}
