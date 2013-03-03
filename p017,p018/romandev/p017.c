#include <stdio.h>

inline static void
check(char (*a_grid)[51], char* a_word)
{
    int offset[8][2] = {
        { -1, -1 }, { 0, -1 }, { 1, -1 },
        { -1,  0 },            { 1,  0 },
        { -1,  1 }, { 0,  1 }, { 1,  1 }
    };

    for ( int y = 0; y < 
}

int main(void)
{
	unsigned int test_case_count;
	unsigned int m, n, k;

	char grid[51][51];
	char word[20][51];

	scanf("%u", &test_case_count);

	for ( int i = 0; i < test_case_count; i++ )
	{
		scanf("%u %u", &m, &n);

		for ( int j = 0; j < m; j++ )
			scanf("%s", grid[j]);

		scanf("%u", &k);

		for ( int j = 0; j < k; j++ )
			scanf("%s", word[j]);

		
	}

	return 0;
}
