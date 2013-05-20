#include <stdio.h>

int day_arr_wkd[3651];
int day_arr_week[3651];
int demo_arr[100];

int main(void)
{
	int case_num;
	int day;
	int counter = 1;
	int demo_num;

	int i,j;

	for(i = 1; i <= 3650 / 7; i++)
	{	
		j = i * 7;
		day_arr_wkd[j] = -1;
		day_arr_wkd[j-1] = -1;
		////printf("day_arr_wkd[%d], [%d] \n", j, j-1);
	}	

	scanf("%d", &case_num);

	while(case_num--)
	{
		scanf("%d", &day);
		scanf("%d", &demo_num);
		for(i = 0; i < demo_num; i++)
		{
			int temp_dem;
			int temp_dem2;
			scanf("%d", &temp_dem);
			//printf("loop %d\n", day / temp_dem);
			for(j = 1; j <= day / temp_dem; j++)
			{
				temp_dem2 = j * temp_dem;
				day_arr_week[temp_dem2] = counter;
				//printf("day_arr_week[%d]\n", temp_dem2 );
			}
		}

		j = 0;
		for(i = 1; i <= day; i++)
		{	
			if(day_arr_wkd[i] != -1 && day_arr_week[i]== counter)
			{
				//printf("yes : day_arr_wkd[%d] = %d, day_arr_week[%d] = %d\n",i,day_arr_wkd[i], i,day_arr_week[i]);
				j++;
			}
			else
			{
				//printf("no : day_arr_wkd[%d] = %d, day_arr_week[%d] = %d\n",i,day_arr_wkd[i], i,day_arr_week[i]);
			}
			
		}

		printf("%d\n", j);
		counter++;
	}
	return 0;
}
