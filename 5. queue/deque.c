#include <stdio.h>

#define MAX_DEQUE_SIZE 10

typedef int element;
typedef struct{
	int front;
	int rear;
	element data[MAX_DEQUE_SIZE];
}Deque;

void init_deque(Deque* d);
int is_empty(Deque* d);
int is_full(Deque* d);
void add_front(Deque* d, element e);
void add_rear(Deque* d, element e);
element delete_front(Deque* d);
element delete_rear(Deque* d);
element get_front(Deque* d);
element get_rear(Deque* d);
void deque_print(Deque* d);

int main()
{
	Deque queue;
	int i;
	init_deque(&queue);
	for (i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}

	
	return 0;
}

void init_deque(Deque* d){
	d->front = 0;
	d->rear = 0;
}

int is_empty(Deque* d){
	if(d->front == d->rear)
		return 1;
	else
		return 0;	
}

int is_full(Deque* d){
	if((d->rear + 1)%MAX_DEQUE_SIZE == d->front)
		return 1;
	else
		return 0;
}

void add_rear(Deque* d, element e){
	if(is_full(d)){
		printf("DEQUE is full.\n");
		exit(1);
	}
	d->rear = (d->rear+1)%MAX_DEQUE_SIZE;
	d->data[d->rear] = e;
}

element delete_front(Deque* d){
	if(is_empty(d)){
		printf("DEQUE is empty.\n");
		exit(1);
	}
	d->front = (d->front + 1)%MAX_DEQUE_SIZE;
	return d->data[(d->front)];
}

element get_front(Deque* d){
	if(is_empty(d)){
		printf("DEQUE is empty.\n");
		exit(1);
	}
	return d->data[(d->front + 1)%MAX_DEQUE_SIZE];
}

//여기서부터 공부 하기! 
void add_front(Deque* d, element e){
		if(is_full(d)){
		printf("DEQUE is full.\n");
		exit(1);
	}
	d->data[d->front] = e;
	d->front = (d->front - 1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE; 
}
element delete_rear(Deque* d){
	if(is_empty(d)){
		printf("DEQUE is empty.\n");
		exit(1);
	} 
	int prev = d->rear;
	d->rear = (d->rear-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
	return d->data[prev];
	
}
element get_rear(Deque* d){
	if(is_empty(d)){
		printf("DEQUE is empty.\n");
		exit(1);
	}
	int prev = d->rear;
	return d->data[prev];
}

void deque_print(Deque* d){
	printf("DEQUE(front=%d rear=%d) = ", d->front, d->rear);
	if (!is_empty(d)) {
		int i = d->front;
		do {
			i = (i + 1) % (MAX_DEQUE_SIZE);
			printf("%d | ", d->data[i]);
			if (i == d->rear)
				break;
		} while (i != d->front);
	}
	printf("\n");

}
