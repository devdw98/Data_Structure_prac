#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

int create();
int init();
int is_empty();
int is_full();
int enqueue();
int dequeue();
int peek();

int main(){
	
	
	return 0;
}
