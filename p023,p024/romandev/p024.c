#include <stdio.h>

int tree[100000] = { 0, };
int tree_height[100000] = { 0, };

inline static void
set_parent(int a_index, int a_parent_index)
{
	tree[a_index] = a_parent_index;
	tree_height[a_index] = tree_height[a_parent_index] + 1;
}

inline static int
get_height(int a_index)
{
	return tree_height[a_index];
}

inline static int
get_parent(int a_index)
{
	return tree[a_index];
}

int main(void)
{
	int test_case_count;
	int n, q;
	int parent;

	scanf("%d", &test_case_count);

	for ( int k = 0; k < test_case_count; k++ )
	{
		scanf("%d %d", &n, &q);
		for ( int i = 1; i < n; i++ )
		{
			scanf("%d", &parent);
			set_parent(i, parent);
		}

		for ( int i = 0; i < q; i++ )
		{
			int a, b;
			int ah, bh;
			int r = 0;

			scanf("%d %d", &a, &b);

			ah = get_height(a);
			bh = get_height(b);

			while ( ah < bh )
			{
				b = get_parent(b);
				bh = get_height(b);
				r++;
			}

			while ( ah > bh )
			{
				a = get_parent(a);
				ah = get_height(a);
				r++;
			}

			while ( a != b )
			{
				a = get_parent(a);
				b = get_parent(b);
				r += 2;
			}

			printf("%d\n", r);
		}
	}

	return 0;
}
