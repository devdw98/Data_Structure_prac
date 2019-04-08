#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5
typedef int element;
typedef struct {
	element* data;
	int front;
	int rear;
	int size;
}Queue;

void queue_init(Queue* q);
int is_full(Queue* q);
int is_empty(Queue* q);
void enqueue(Queue* q, element e);
element dequeue(Queue* q);
element peek(Queue* q);
void queue_print(Queue* q);

int main()
{
	Queue q;
	int element;
	int i;
	queue_init(&q); queue_print(&q);
	enqueue(&q,1); queue_print(&q);
	enqueue(&q,2); queue_print(&q);
//	dequeue(&q); queue_print(&q);
	enqueue(&q,3); queue_print(&q);
	enqueue(&q,4); queue_print(&q);
	enqueue(&q,5); queue_print(&q);
	enqueue(&q,6); queue_print(&q);
	dequeue(&q); queue_print(&q);
	
	free(q.data);
	return 0;
}

void queue_init(Queue* q){
	q->front = 0;
	q->rear = 0;
	q->size = INITIAL_SIZE;
	q->data = (element*)malloc(q->size * sizeof(element));
}
int is_full(Queue* q){
	return (q->rear+1)%q->size == q->front;
}
int is_empty(Queue* q){
	return (q->rear) == (q->front);
}
void enqueue(Queue* q, element e){
	if(is_full(q)){
		printf("SIZE %d ->",q->size);
		q->size *= 2;
		q->data = (element*)realloc(q->data, q->size*sizeof(element));
		printf(" %d\n",q->size);
	}
	q->rear = (q->rear + 1)%q->size; //ÁÖÀÇ 
	q->data[(q->rear)] = e;
}

element dequeue(Queue* q){
	if(is_empty(q)){
		printf("QUEUE is empty.\n");
		exit(1);
	}
	q->front = (q->front + 1)%q->size;
	return q->data[(q->front)];
}

element peek(Queue* q){
	if(is_empty(q)){
		printf("QUEUE is empty.\n");
		exit(1);
	}
	return q->data[q->front + 1];
}

void queue_print(Queue* q){
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
			int i = q->front;
			do {
				i = (i + 1) % (q->size);
				printf("%d | ", q->data[i]);
				if (i == q->rear)
					break;
			} while (i != q->front);
		}
	printf("\n");	
}
