#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#define debug(a_arg, ...) { \
	printf("[%10s():%d] " a_arg "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); \
	fflush(stdout); \
	}

#ifndef DEBUG
#define debug
#endif

typedef struct Node
{
	struct Node* next;
	int          value;	
} Node;

typedef struct Queue
{
	Node* head;
	Node* tail;
	int   size;
} Queue;

static void
enq(Queue* a_queue, int a_value)
{
	if ( a_queue == NULL )
		return;

	if ( a_queue->tail == NULL )
	{
		a_queue->tail = a_queue->head = (Node*)malloc(sizeof(Node));
		a_queue->tail->value = a_value;
		a_queue->tail->next = NULL;
	}
	else
	{
		a_queue->tail->next = (Node*)malloc(sizeof(Node));
		a_queue->tail = a_queue->tail->next;
		a_queue->tail->value = a_value;
		a_queue->tail->next = NULL;
	}

	a_queue->size++;
}

static int
deq(Queue* a_queue)
{
	if ( a_queue == NULL )
		return -1;

	if ( a_queue->size )
	{
		Node* target = a_queue->head;
		int   value = target->value;

		if ( a_queue->head == a_queue->tail )
			a_queue->tail = NULL;

		a_queue->head = a_queue->head->next;

		free(target);
		a_queue->size--;

		return value;
	}

	return -1;
}

static int
is_empty(Queue* a_queue)
{
	if ( a_queue == NULL )
		return -1;

	return a_queue->size == 0;
}

int main(void)
{
	int   test_cases;
	int   r;
	int   s[500];
	int   vito;
	Queue buckets[10] = { 0, };

	scanf("%d", &test_cases);
	for ( int i = 0; i < test_cases; i++ )
	{
		scanf("%d", &r);
		for ( int j = 0; j < r; j++ )
		{
			scanf("%d", s + j);
			enq(buckets + (s[j] % 10), s[j]);
		}

		for ( int j = 0; j < r; j++ )
			for ( int k = 0; k < 10; k++ )
				if ( !is_empty(buckets + k) )
				{
					s[j] = deq(buckets + k);
					break;
				}

		int flag_sum = 1;
		int divider = 10;

		while ( flag_sum )
		{
			flag_sum = 0;

			for ( int j = 0; j < r; j++ )
			{
				int key = s[j] / divider % 10;

				flag_sum += key;
				enq(buckets + key, s[j]);
			}

			for ( int j = 0; j < r; j++ )
				for ( int k = 0; k < 10; k++ )
					if ( !is_empty(buckets + k) )
					{
						s[j] = deq(buckets + k);
						break;
					}

			divider *= 10;
		}

		vito = s[r / 2];

		int diff_sum = 0;
		for ( int j = 0; j < r; j++ )
		{
			int diff = vito - s[j];
			diff = diff > 0 ? diff : -diff;

			diff_sum += diff;
		}

		printf("%d\n", diff_sum);
	}

	return 0;
}
