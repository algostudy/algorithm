#include <iostream>

using namespace::std;

#define MOD 1000000007
int cache[101];

int test(int w)
{
	//cout << "test " << w << endl;
	int& ret = cache[w];
	if(ret != 0) 
	{
		//cout << "ret != 0 " << endl;	
		return ret;
	}
	return ret = (test(w-2) + test(w-1)) %MOD;
}

int asy_test(int w)
{
	int result;
	if(w % 2 == 1)// 홀수
	{
		result = (test(w) - test(w >> 1) + MOD) % MOD;
		return result;
	}
	
	result = (test(w) - test(w>>1) + MOD) % MOD;
	//cout << result << endl;
	//cout << test(w) << " " << test(w>>1) << endl;
	result = (result - test((w>>1) - 1) + MOD) % MOD;
	//cout << result << " " << test(w>>1 -1) << endl;
	//printf("%d %d \n", w >> 1 , test(2));
	return result;
}

int main()
{
	int num_test;
	int result;

	cin >> num_test;

	cache[0] = 1;
	cache[1] = 1;
	//test(100);
	//for(int i = 1; i <= 100; i++)
	//		cout << cache[i] << endl;
	
	while(num_test--)
	{
		int num;
		cin >> num;
		//num = 6;
		result = asy_test(num);
		
		cout << result << endl;
	}

	return 0;
}
