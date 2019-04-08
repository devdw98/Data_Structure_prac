#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 5

typedef char element;
typedef struct{
	int size;
	int front;
	int rear;
	element* data;
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

int absolute(int a, int b){
	if(a>b)
		return a-b;
	else
		return b-a;
}

int palindrome(Deque* d, char* c){
	init_deque(d);
	int i, len;
	len = strlen(c);
	printf("%d\n",len);
	for(i=0;i<len;i++){
		add_rear(d,c[i]);
		deque_print(d);
	}
	if(len%2==0){ //짝수 
		while(!is_empty(d)){
			if(get_rear(d)==get_front(d)){
				delete_rear(d);
				delete_front(d);
				deque_print(d);
			}
			else{
				printf("\"%s\" isn't a palindrome string.\n",c);
				return 0;
			}		
		}
	}
	else{ //홀수 
		while(!is_empty(d)){
			if(get_rear(d)==get_front(d)){
				delete_rear(d);
				delete_front(d);
				deque_print(d);
				if(absolute(d->front,d->rear) == 1)
					break;
			}
			else{
				printf("\"%s\" isn't a palindrome string.\n",c);
				return 0;
			}
		}
	}
	printf("\"%s\"\" is a palindrome string.\n",c);
	return 0;
}


int main()
{
	Deque q;
	int i, number=0;
	char* ch;
	printf("Enter the number you typing String: ");
	scanf("%d",&number);
	printf("%d typing\n",number);
	for(i=0;i<number;i++){
		printf("Input a String\n");
		scanf("%s",&ch);
		palindrome(&q,&ch);
		printf("\n");
	}
	free(q.data);
	return 0;
}

void init_deque(Deque* d){
	d->front = 0;
	d->rear = 0;
	d->size = INITIAL_SIZE;
	d->data = (element*)malloc(d->size*sizeof(element));
}

int is_empty(Deque* d){
	if(d->front == d->rear)
		return 1;
	else
		return 0;	
}

int is_full(Deque* d){
	if((d->rear + 1)% d->size == d->front)
		return 1;
	else
		return 0;
}

void add_rear(Deque* d, element e){
	if(is_full(d)){
		printf("SIZE : %d ",d->size);
		d->size *= 2;
		d->data = (element*)realloc(d->data, d->size*sizeof(element));
		printf("-> %d\n",d->size);
	}
	d->rear = (d->rear+1)%d->size;
	d->data[d->rear] = e;
}

element delete_front(Deque* d){
	if(is_empty(d)){
		printf("DEQUE is empty.\n");
		exit(1);
	}
	d->front = (d->front + 1)% d->size;
	return d->data[(d->front)];
}

element get_front(Deque* d){
	if(is_empty(d)){
		printf("DEQUE is empty.\n");
		exit(1);
	}
	return d->data[(d->front + 1)% d->size];
}

//여기서부터 공부 하기! 
void add_front(Deque* d, element e){
	if(is_full(d)){
		printf("SIZE : %d ",d->size);
		d->size *= 2;
		d->data = (element*)realloc(d->data, d->size*sizeof(element));
		printf("->%d\n",d->size);
	}
	d->data[d->front] = e;
	d->front = (d->front - 1+ d->size )% d->size; 
}
element delete_rear(Deque* d){
	if(is_empty(d)){
		printf("DEQUE is empty.\n");
		exit(1);
	} 
	int prev = d->rear;
	d->rear = (d->rear-1+d->size)%d->size;
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
			i = (i + 1) % (d->size);
			printf("%c | ", d->data[i]);
			if (i == d->rear)
				break;
		} while (i != d->front);
	}
	printf("\n");

}



