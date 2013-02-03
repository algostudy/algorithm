#include <stdio.h>
#include <math.h>

typedef unsigned int uint32;

typedef struct set
{
	struct set* parent;
	uint32      value;
} set;

static void
make_set(set* a_set, uint32 a_value)
{
	a_set->parent = NULL;
	a_set->value = a_value;
}

static set*
find_root(set* a_set)
{
	if ( a_set != NULL && a_set->parent != NULL )
	{
		a_set->parent = find_root(a_set->parent);
		return a_set->parent;
	}

	return a_set;
}

static void
union_set(set* a_set1, set* a_set2)
{
	set* root = find_root(a_set2);
	root->parent = a_set1;
}
                                                                                                                                                                  
typedef struct
{
        double x;
        double y;
        set    disjoint;
} node;

typedef struct
{
        double weight;
        set*   node1;
        set*   node2;
} edge;

inline static void
quick_sort(edge a_data[], int a_length)
{
	int left = 0;
	int right = a_length;
	double pivot = a_data[0].weight;
	edge temp;

	if ( a_length > 1 )
	{
		while ( 1 )
		{
			while ( a_data[++left].weight < pivot ) ;
			while ( a_data[--right].weight > pivot ) ;

			if ( left >= right ) break;

			temp = a_data[left];
			a_data[left] = a_data[right];
			a_data[right] = temp;
		}

		temp = a_data[0];
		a_data[0] = a_data[right];
		a_data[right] = temp;

		quick_sort(a_data, right);
		quick_sort(a_data + right + 1, a_length - right - 1);
	}
}

inline static double
get_weight(node a_node1, node a_node2)
{
	double x_vector = (a_node1.x - a_node2.x);
	double y_vector = (a_node1.y - a_node2.y);

	return sqrt(x_vector * x_vector + y_vector * y_vector);
}

inline static uint32
make_edge_list(node a_nodes[], uint32 a_n, edge a_edges[])
{
	uint32 edge_count = a_n * (a_n - 1) / 2;
	uint32 real_count = 0;

	for ( int i = 0; i < a_n; i++ )
		for ( int j = i + 1; j < a_n; j++ )
		{
			a_edges[real_count].weight = get_weight(a_nodes[i], a_nodes[j]);
			a_edges[real_count].node1 = &a_nodes[i].disjoint;
			a_edges[real_count].node2 = &a_nodes[j].disjoint;
			real_count++;
		}

	return edge_count;
}

inline static double
kruskal(node a_nodes[], uint32 a_n)
{
	double sum;
	uint32 count;
	uint32 edge_count;
	edge   edges[5000] = { 0, };

	sum = 0.0;
	count = 0;

	edge_count = make_edge_list(a_nodes, a_n, edges);
	quick_sort(edges, edge_count);

	for ( int i = 0; i < edge_count && count < a_n - 1; i++ )
	{
		if ( find_root(edges[i].node1) != find_root(edges[i].node2) )
		{
			union_set(edges[i].node1, edges[i].node2);

			count++;
			sum += edges[i].weight;
		}
	}

	return sum;
}

int main(void)
{
        uint32 test_case_count;
        uint32 n;
        node   nodes[100] = { 0, };

        scanf("%u", &test_case_count);
        for ( int i = 0; i < test_case_count; i++ )
        {
                scanf("%u", &n);
                for ( int j = 0; j < n; j++ )
                {
                        scanf("%lf %lf", &nodes[j].x, &nodes[j].y);
						make_set(&nodes[j].disjoint, j);
                }

                printf("%.2lf\n", kruskal(nodes, n));
        }

        return 0;
}
