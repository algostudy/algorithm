#include <stdio.h>

int main(void)
{
	long lbound, ubound, lbOrg, ubOrg, temp;
	//lbound, ubound - 두 수를 입력받음
	//lbOrg, ubOrg - 입력된 두 수를 저장하고, 출력할때 쓰임
	//temp - 입력된 구간 값중 앞의 것이 클때 교환할때 쓰일 임시변수
	long i, j, length, max_length;
	
	while(scanf("%ld %ld", &lbound, &ubound) == 2)
	{
		lbOrg = lbound;
		ubOrg = ubound;
		//입력된 구간 값들 중 앞의 것이 더 크면 교환한다.
		if(lbound > ubound)
		{
			temp = lbound;
			lbound = ubound;
			ubound = temp;
		}

		max_length = 0;
		for(i=lbound; i<=ubound; i++)
		{
			j=i;
			length = 1;

			while(j != 1)
			{
				if(j & 1) //j와 1의 논리합..j가 홀수일 경우 실행
				{
					j = j * 3 + 1;
					length++;
				}
				while(!(j & 1))
				{
					j >>= 1; //쉬프트연산 2로 나눠줌
					length++;
				}
			}

			if(length > max_length)
			{
				max_length = length;
			}
		}

		printf("%ld %ld %ld\n", lbOrg, ubOrg, max_length);
	}
	return 0;
}
