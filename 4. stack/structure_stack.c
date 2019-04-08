#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void create(StackType* s);
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

void create(StackType* s){
	s->top = -1;
}
int is_full(StackType* s){
	return s->top == MAX_STACK_SIZE -1;
}
int is_empty(StackType* s){
	return s->top == -1;
}
void push(StackType* s, element item){
	if(is_full(s)){
		printf("STACK is full.\n");
		exit(1);
	}
	s->data[++(s->top)] = item;
}
element pop(StackType* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		exit(1);
	}
	return s->data[((s->top)--)];
}
element peek(StackType* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		exit(1);
	}
	return s->data[s->top];
}
