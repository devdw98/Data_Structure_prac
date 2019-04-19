#include <stdio.h>

#define MAX_STACK 10

typedef int element;

typedef struct{
	element item[MAX_STACK];
	int top;
}Stack;

int is_empty(Stack* s);
int is_full(Stack* s);
void create(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);
element peek(Stack* s); 

int main()
{
	Stack s;
	create(&s);
	int i;
	for(i=0;i<3;i++){
		push(&s, i);
		printf("%d\n",pop(&s));
	}
	 
	return 0;
}

void create(Stack* s){
	s->top = -1;
//	return s;
}
int is_empty(Stack* s){
	if(s->top == -1) return 1;
	return 0;
}
int is_full(Stack* s){
	if(s->top == MAX_STACK-1) return 1;
	return 0;
}
void push(Stack* s, element item){
	if(is_full(s)){
		printf("STACK is full.\n");
		return;
	}
	s->item[++(s->top)] = item;
}
element pop(Stack* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		return 0;
	}
	return s->item[(s->top)--];
}
element peek(Stack* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		return 0;
	}
	return s->item[(s->top)];
}
