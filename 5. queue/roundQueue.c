#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct{
	int rear;
	int front;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void queue_init(QueueType* q);
int is_full(QueueType* q);
int is_empty(QueueType* q);
void enqueue(QueueType* q, element e);
element dequeue(QueueType* q);
element peek(QueueType* q);
void queue_print(QueueType* q);

int main()
{
	QueueType q;
	int element;
	queue_init(&q); queue_print(&q);
	enqueue(&q,1); queue_print(&q);
	enqueue(&q,2); queue_print(&q);
	dequeue(&q); queue_print(&q);
	enqueue(&q,3); queue_print(&q);
	enqueue(&q,4); queue_print(&q);
	enqueue(&q,5); queue_print(&q);
	enqueue(&q,6); queue_print(&q);
	dequeue(&q); queue_print(&q);
	
	return 0;

}

void queue_init(QueueType* q){
	q->front = 0;
	q->rear = 0;
}
int is_full(QueueType* q){ //외우기 
	if(q->front == (q->rear + 1)%MAX_QUEUE_SIZE)
		return 1;
	else
		return 0;
} 
int is_empty(QueueType* q){
	if(q->rear == q->front)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, element e){
	if(is_full(q)){
		printf("QUEUE is full.\n");
		exit(1);
	}
	q->rear = (q->rear + 1)%MAX_QUEUE_SIZE; //주의 
	q->data[(q->rear)] = e;
} 

element dequeue(QueueType* q){
	if(is_empty(q)){
		printf("QUEUE is empty.\n");
		exit(1);
	}
	q->front = (q->front + 1)%MAX_QUEUE_SIZE;
	return q->data[(q->front)];
}

element peek(QueueType* q){
	if(is_empty(q)){
		printf("QUEUE is empty.\n");
		exit(1);
	}
	return q->data[q->front + 1];
}

void queue_print(QueueType* q){
/*	int i;
	for(i=0;i<MAX_QUEUE_SIZE;i++){
		if(i<=q->front || i>q->rear)
			printf(" |");
		else
			printf("%d|",q->data[i]);
	}
	printf("\n");*/
	
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
			int i = q->front;
			do {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				printf("%d | ", q->data[i]);
				if (i == q->rear)
					break;
			} while (i != q->front);
		}
	printf("\n");

	
}
