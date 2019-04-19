#include <stdio.h>
#define MAX_LEN 10
typedef struct{
	int front;
	int rear;
	element customer[MAX_LEN];
}Queue;

typedef struct{
	int id; // 고객 
	int arrival_time; //도착시간 
	int service_time; //서비스 받는 시간  
}element;

int is_empty(Queue* q);
int is_full(Queue* q);
int create(Queue* q);
void enqueue(Queue* q, element customer);
element dequeue(Queue* q);

int main(){
	
	
	return 0;
}
int is_empty(Queue* q){
	if(q->front == q->rear) return 1;
	return 0;
}
int is_full(Queue* q){
	if((q->rear+1)%MAX_LEN == q->front) return 1;
	return 0;
}
void create(Queue* q){
	q->front = 0;
	q->rear = 0;
}
void enqueue(Queue* q, element customer){
	if(is_full(q)){
		printf("Customer is FULL.\n");
		return 0;
	}
	q->rear = (q->rear+1)%MAX_LEN;
	q->customer[q->rear] = customer;
}
element dequeue(Queue* q){
	if(is_empty(q)){
		printf("Customer is empty.\n");
		return 0;
	}
//	element customer;
	q->front = (q->front+1)%MAX_LEN;
	return q->customer[q->front];
	
}

