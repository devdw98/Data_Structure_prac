#include <stdio.h>

#define MAX_LENGTH 5
typedef int element;
typedef struct{
	element* item;
	int capacity; //현재위치 
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
	Stack *s = (Stack*)malloc(sizeof(Stack));

	create(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", peek(s));
	printf("%d\n", pop(s));
	free(s);

		
	return 0;
}
void create(Stack* s){
	s->item = (element*)malloc(sizeof(element)*MAX_LENGTH);
	s->capacity = MAX_LENGTH;
	s->top = -1;
}
int is_empty(Stack* s){
	if(s->top == -1) return 1;
	return 0;
}
int is_full(Stack* s){
	if(s->top == s->capacity -1) return 1;
	return 0;
}
void push(Stack* s, element item){
	if(is_full(s)){
		s->capacity *=2;
		s->item = (element*)realloc(s->item,sizeof(element)*s->capacity);
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
