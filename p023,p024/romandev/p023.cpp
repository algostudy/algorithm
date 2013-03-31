#include <cstdio>
#include <cstdlib>
#include <deque>

using namespace std;

typedef struct
{
        char raw_data[8];
        int  number;
} node;

node g_input_datas[10000];
char g_restrict_table[10000];
char g_prev_table[10000];
int  g_key = 0;

char g_inc_map[] = "1234567890";
char g_dec_map[] = "9012345678";

int get_number(node* a_node)
{
        int number = 0;
        int position = 1000;

        if ( number != 0 )
                return number;

        for ( int i = 0; i < 8; i += 2 )
        {
                number += (a_node->raw_data[i] - '0') * position;
                position /= 10;
        }

        return number;
}

int get_weight(node* a_node1, node* a_node2)
{
        int sum = 0;

        for ( int i = 0; i < 8; i += 2 )
                sum += abs((a_node1->raw_data[i]) - (a_node2->raw_data[i]));

        return sum;
}

int get_min_value(node* a_source, node* a_dest, int a_count)
{
        int source_number = get_number(a_source);
        int dest_number = get_number(a_dest);
        int source_weight = get_weight(a_source, a_dest);

		g_prev_table[source_number] = g_key;
        deque<node> deq;

        if ( source_weight == 0 )
                return a_count;

        for ( int i = 0; i < 8; i += 2 )
        {
                node new_source = { "0 0 0 0", 0 };
                int  new_source_weight;
                int  new_source_number;

                for ( int j = 0; j < 8; j += 2 )
                {
                        if ( i == j )
                                new_source.raw_data[i] = g_inc_map[a_source->raw_data[i] - '0'];
                        else
                                new_source.raw_data[j] = a_source->raw_data[j];
                }

                new_source_number = get_number(&new_source);

                if ( g_restrict_table[new_source_number] != g_key && g_prev_table[new_source_number] != g_key )
                {
                        new_source_weight = get_weight(&new_source, a_dest);
                        if ( source_weight > new_source_weight )
                                deq.push_front(new_source);
                        else
                                deq.push_back(new_source);
                }
        }

        for ( int i = 0; i < 8; i += 2 )
        {
                node new_source = { "0 0 0 0", 0 };
                int  new_source_weight;
                int  new_source_number;

                for ( int j = 0; j < 8; j += 2 )
                {
                        if ( i == j )
                                new_source.raw_data[i] = g_dec_map[a_source->raw_data[i] - '0'];
                        else
                                new_source.raw_data[j] = a_source->raw_data[j];
                }

                new_source_number = get_number(&new_source);

                if ( g_restrict_table[new_source_number] != g_key && g_prev_table[new_source_number] != g_key )
                {
                        new_source_weight = get_weight(&new_source, a_dest);
                        if ( source_weight > new_source_weight )
                                deq.push_front(new_source);
						else
                                deq.push_back(new_source);
                }
        }

        for ( int i = 0; i < deq.size(); i++ )
        {
                int ret = get_min_value(&deq.at(i), a_dest, a_count + 1);
                if ( ret >= 0 ) return  ret;
        }

		g_prev_table[source_number] = g_key - 1;

        return -1;
}

int read_count()
{
        char buffer[1024];

        gets(buffer);
        return atoi(buffer);
}

int main(void)
{
        node source = { 0, };
        node dest = { 0, };
        int  restrict_count;
        int  test_case_count;
        char blank[1024];

        test_case_count = read_count();
        for ( int i = 0; i < test_case_count; i++ )
        {
                g_key++;

                gets(blank);
                gets((char*)&source);
                gets((char*)&dest);

                restrict_count = read_count();
                for ( int j = 0; j < restrict_count; j++ )
                {
                        int number;

                        gets((char*)&g_input_datas[j]);
                        number = get_number(&g_input_datas[j]);
                        g_restrict_table[number] = g_key;
                }

                printf("%d\n", get_min_value(&source, &dest, 0));
                fflush(stdout);
        }

        return 0;
}

