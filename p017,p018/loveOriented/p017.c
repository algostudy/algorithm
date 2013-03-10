#include <stdio.h>

#define MAX 50

int grid[MAX][MAX];
int word[MAX];
int grid_row;
int grid_col;
int word_len;

int factor[8][2] =
{
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1}
};

int is_word_right(int x, int y, int factor_x, int factor_y)
{
	int i;
	
	for( i=1 ; i<word_len ; i++)
	{
		x += factor_x;
		y += factor_y;
		if(x < 0 || y < 0)
			return 0;

		if(x >= grid_row || y >= grid_col)
			return 0;

		if(grid[x][y] != word[i])
			return 0;
	}
	//printf("success!\n");
	return 1;
}

int check_word(int x, int y)
{
	int i;
	int factor_x;
	int factor_y;
	for( i=0 ; i<8; i++)
	{
		if(is_word_right(x,y, factor[i][0], factor[i][1]))
		{
			return 1;
		}	
	}
	return 0;
}

int find_word_location(int *x, int *y)
{
	int i,j;
	for( i=0 ; i<grid_row ; i++)
	{
		for( j=0 ; j<grid_col ; j++)
		{
			if(grid[i][j] == word[0])
			{
				if(check_word(i,j))
				{
					*x = i+1;
					*y = j+1;
					return 1;
				}
			}
		}
	}

	//no word in the grid
	return 0; 
}

int main()
{
	int case_num;

	scanf("%d", &case_num);
	while(case_num--)
	{
		char temp;
		int i,j;
		int sub_case_num;
		scanf("%c", &temp);
		scanf("%d %d", &grid_row, &grid_col);
		scanf("%c", &temp); // 10(line feed)

		//printf("row %d col %d\n", grid_row, grid_col);
		for(i = 0 ; i < grid_row ; i++)
		{
			char c;
			for(j = 0 ; j < grid_col ; j++)
			{
				scanf("%c", &c);
				if(c >= 97)
				{
					c -= 32;
				}
				grid[i][j] = c;
			}
			scanf("%c", &c);
		}

		#if	 0 
		for(i=0 ; i<grid_row ; i++)
		{
			for(j=0; j<grid_col ; j++)
			{
				printf("%c", grid[i][j]);
			}
			printf("\n");
		}
		#endif

		scanf("%d", &sub_case_num);
		scanf("%c", &temp); //
		//printf("sub case : %d\n", sub_case_num);

		while(sub_case_num--)
		{
			char c;
			int x,y;
			word_len = 0;
			while((scanf("%c", &c) == 1) && (c != 10))
			{
				if(c >= 97)
				{
					c -= 32;
				}
				word[word_len++] = c;
			}

			//printf("word_len %d\n", word_len);
			#if 0 
			{
				int i;
				for(i=0; i<word_len ; i++)
				{	
					printf("[%c][%d]\n",word[i], word[i]);
				}
			}
			#endif	
			x = 0;
			y = 0;
			if(find_word_location(&x, &y))
			{
				printf("%d %d\n", x, y);
			}
		}	
		printf("\n");
	}

	return 0;
}
