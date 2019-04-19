#include <stdio.h>

#define MAX_LEN 5
typedef int element;
typedef struct{
	int front;
	int rear;
	element data[MAX_LEN];
}Queue;

void create(Queue* q);
int is_full(Queue* q);
int is_empty(Queue* q);
void enqueue(Queue* q, element data);
element dequeue(Queue* q);
void print_queue(Queue* q);

int main(){
	Queue q;
	create(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	printf("%d\n",dequeue(&q));
	printf("%d\n",dequeue(&q));		
	printf("%d\n",dequeue(&q));
	return 0;
}
void create(Queue* q){
	q->front = 0;
	q->rear = 0;
}
int is_full(Queue* q){
	if((q->rear+1)%MAX_LEN == q->front) return 1;
	return 0;
}
int is_empty(Queue* q){
	if(q->front == q->rear) return 1;
	return 0;
}
void enqueue(Queue* q, element data){
	if(is_full(q)){
		printf("Queue is FULL.\n");
		return 0;
	}
	q->rear = (q->rear + 1)% MAX_LEN;
	q->data[q->rear] = data;
}
element dequeue(Queue* q){
	if(is_empty(q)){
		printf("Queue is EMPTY.\n");
		return 0;
	}
	q->front = (q->front + 1)%MAX_LEN;
	return q->data[q->front];
}
