#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10 //스택의 최대 크기
#define INITIAL_CAPACITY 2

typedef int element;
typedef struct{
	element* data;
	int capacity;
	int top;
}StackType;

int create(StackType* s);
int is_full(StackType* s);
int is_empty(StackType* s);
void push(StackType* s, element item);
element pop(StackType* s);
element peek(StackType* s);

int main()
{
	StackType s;
	create(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",peek(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	return 0;
}
int create(StackType *s){
	s->top = -1;
	s->capacity = INITIAL_CAPACITY; //맘대로 설정한 초기 크기
	s->data = (element *)malloc(s->capacity * sizeof(element));
}
int is_full(StackType* s){
	if(s->top == (s->capacity) - 1)
		return 1;
	else
		return 0;
}

int is_empty(StackType* s){
	if(s->top == -1)
		return 1;
	else
		return 0;	
}
void push(StackType* s, element item){
	if(is_full(s)){
		s->capacity *=2;
		s->data = (element*)realloc(s->data, s->capacity*sizeof(element));
	}
	s->data[++(s->top)] = item;
}
element pop(StackType* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		exit(1);
	}
	return s->data[(s->top)--];
}
element peek(StackType* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		exit(1);
	}
	return s->data[s->top];
}
