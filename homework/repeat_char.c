#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_CAPACITY 2

typedef char element;
typedef struct {
	element* data;
	int top;
	int capacity;
}Stack;

int create(Stack* s);
int is_full(Stack* s);
int is_empty(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);
element peek(Stack* s);

int repeat_char(const char* c);

int main()
{
	char* a = "abcade";
	char* b = "abccba";
	char* c = "abbbba";
	repeat_char(a);
	repeat_char(b);
	repeat_char(c);
	
	return 0;
}

int create(Stack* s){
	s->top = -1;
	s->capacity = INITIAL_CAPACITY;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}
int is_full(Stack* s){
	if(s->top == s->capacity-1){
	return 1;
	}
	return 0;
}
int is_empty(Stack* s){
	if(s->top == -1){
		return 1;
	}
	else
		return 0;
}
void push(Stack* s, element item){
	if(is_full(s)){
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity*sizeof(element));
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

int repeat_char(const char* c){
	Stack* s;
	create(&s);
	char ch, peek_ch;
	int i, len;
	len = strlen(c);
	if(len%2 == 0){ //STACK
		printf("%s는 짝수입니다.\n",c);
		for(i=0;i<len;i++){
			ch = c[i];
		//	printf("%c\n",ch);
			if(is_empty(&s))
				push(&s,ch);
			else{
				peek_ch = peek(&s);
				if(peek_ch == ch){
					pop(&s);
				}
				else{
					push(&s,ch);
				}
			}
		}
		if(is_empty(&s))
			printf("%s는 도돌이문입니다.\n",c);
		else{
			printf("%s는 도돌이문이 아닙니다.\n",c);
		}
	}
	else{ //QUEUE
		printf("%s는 홀수 입니다.\n",c);
	}
	return 1;
	
}
