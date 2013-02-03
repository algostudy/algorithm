#include <stdio.h>

typedef enum
{
	FALSE,
	TRUE
} boolean;

typedef enum
{
	WHITE,
	RED,
	BLACK
} color;

static color   g_nodes[200] = { 0, };
static int     g_edges[200][200] = { 0, };
static boolean g_bicolorable = TRUE;

static void
set_link(int a_x, int a_y, int a_key)
{
	g_edges[a_x][a_y] = a_key;
	g_edges[a_y][a_x] = a_key;
}

static void
dfs(int a_node, int a_color, int a_node_count, int a_key)
{
	g_nodes[a_node] = a_color;

	for ( int i = 0; i < a_node_count && g_bicolorable; i++ )
	{
		if ( g_edges[a_node][i] == a_key )
		{
			int new_color = (a_color == RED ? BLACK : RED);

			if ( g_nodes[i] == 0 )
				dfs(i, new_color, a_node_count, a_key);
			else if ( g_nodes[i] == a_color )
				g_bicolorable = 0;
		}
	}
}

int main(void)
{
	int node_count;
	int edge_count;
	int x, y;
	int key = 0;
	char* status[] = { "NOT BICOLORABLE", "BICOLORABLE" };

	while ( scanf("%d", &node_count) == 1 && node_count != 0 )
	{
		scanf("%d", &edge_count);
		key++;

		for ( int i = 0; i < node_count; i++ )
			g_nodes[i] = WHITE;

		for ( int i = 0; i < edge_count; i++ )
		{
			scanf("%d %d", &x, &y);
			set_link(x, y, key);
		}

		g_bicolorable = TRUE;
		dfs(x, RED, node_count, key);

		printf("%s\n", status[g_bicolorable]);
	}

	return 0;
}
