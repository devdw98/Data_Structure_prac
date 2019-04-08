#include <stdio.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
	int front; //맨 앞 표시 
	int rear; //top역 할 
	element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType* q);
void queue_print(QueueType* q);
int is_full(QueueType* q);
int is_empty(QueueType* q);
void enqueue(QueueType* q, element e);
element dequeue(QueueType* q);
element peek(QueueType* q);

int main()
{
	element item=0; 
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);

	
	return 0;
}

void init_queue(QueueType* q){
	q->front = -1;
	q->rear = -1;
}
int is_full(QueueType* q){ //다시 
	if(q->rear == MAX_QUEUE_SIZE-1)
		return 1;
	else
		return 0;
} 
int is_empty(QueueType* q){  //다시  
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}
void enqueue(QueueType* q, element e){
	if(is_full(q)){
		printf("QUEUE is full.\n");
		exit(1);
	}
	q->data[++(q->rear)] = e;
}

element dequeue(QueueType* q){
	if(is_empty(q)){
		printf("QUEUE is empty.\n");
		exit(1);
	}
	return q->data[++(q->front)];
}

element peek(QueueType* q){
	if(is_empty(q)){
		printf("QUEUE is empty.\n");
		exit(1);
	}
	return q->data[q->front + 1];
}
void queue_print(QueueType* q){  
	int i;
	for(i=0;i<MAX_QUEUE_SIZE;i++){
		if(i<=q->front || i>q->rear) //다시 
			printf(" |");
		else
			printf("%d |",q->data[i]); 
	}
	printf("\n");
}
