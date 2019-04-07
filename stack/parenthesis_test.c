#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10 //스택의 최대 크기
#define INITIAL_CAPACITY 2

typedef char element;

typedef struct{
	int top;
	int capacity;
	element* data;
}Stack;

int create(Stack* s);
int is_full(Stack* s);
int is_empty(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);
element peek(Stack* s);

int check_matching(const char* in);
int main()
{
	char *p ="[a+{b-c*(4+5)}+d]]";
	if (check_matching(p) == 1) 
		printf("%s 괄호검사성공\n", p);
	else
		printf("%s 괄호검사실패\n", p);
	return 0;


}

int create(Stack* s){
	s->top = -1;
	s->capacity = INITIAL_CAPACITY;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}
int is_full(Stack* s){
	if(s->top == s->capacity -1)
		return 1;
	else
		return 0;
}
int is_empty(Stack* s){
	if(s->top == -1)
		return 1;
	else
		return 0;
}

void push(Stack* s, element item){
	if(is_full(s)){
		s->capacity *=2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(Stack* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

element peek(Stack* s){
	if(is_empty(s)){
		printf("STACK is empty.\n");
		exit(1);
	}
	return s->data[s->top];
}

int check_matching(const char* in){
	Stack s;
	char ch, pop_ch;
	int i, len;
	len = strlen(in);
	create(&s);
	
	for(i=0;i<len;i++){
		ch = in[i];
		switch(ch){
			case '(': case '{': case '[':
				push(&s,ch);
				break;
			case ')': case '}': case ']' :
				if(is_empty(&s)){
					printf("괄호가 부족합니다.\n");
					return 0;
				}

				pop_ch = pop(&s);
				if(pop_ch == '(' && ch != ')' || pop_ch == '{' && ch !='}' && pop_ch == '[' && ch != ']'){
					return 0;
				}
		}
	}
	return 1;
	
}
