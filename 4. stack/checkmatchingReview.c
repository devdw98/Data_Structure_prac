#include <stdio.h>
#define MAX_LEN 5;

typedef char element;
typedef struct{
	int top;
	int capacity;
	element* data;
}Stack;

void create(Stack* s);
int is_full(Stack* s);
int is_empty(Stack* s);
void push(Stack* s, element data);
element pop(Stack* s);
element peek(Stack* s);
void check_matching(Stack* s, const char* ln);

int main()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	create(s);
	char* p ="{ A[(i+1)]=0; }";
	check_matching(s,p);
	return 0;
}

void create(Stack* s){
	s->capacity = MAX_LEN;
	s->top = -1;
	s->data = (element*)malloc(sizeof(element)*s->capacity);
}
int is_full(Stack* s){
	if(s->top == s->capacity -1) return 1;
	return 0;
}
int is_empty(Stack* s){
	if(s->top == -1) return 1;
	return 0;
}
void push(Stack* s, element data){
	if(is_full(s)){
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, sizeof(element)*s->capacity);
	}
	s->data[++(s->top)] = data;
}
element pop(Stack* s){
	if(is_empty(s)){
		printf("STACK is NULL.\n");
		return 0;
	}
	return s->data[(s->top)--];
}
element peek(Stack* s){
		if(is_empty(s)){
		printf("STACK is NULL.\n");
		return 0;
	}
	return s->data[(s->top)];
}
void check_matching(Stack* s,const char* p){
	if(p==NULL){
		printf("STOP\n");
		return 0;
	}
	char ch, open_ch;
	int len = strlen(p);
	int i;
	for(i=0;i<len;i++){
		ch = p[i];
		printf("%c\n",ch);
		switch(ch){
			case '(':
			case '{': 
			case '[':
				push(s,ch);
				break;
			case ')': 
				if(peek(s)==')'){
					pop(s);
				}
				break;
			case '}': 
				if(peek(s)=='}'){
					pop(s);
				}
				break;
			case ']':
				if(peek(s)==']'){
					pop(s);
				}
				break;
			default:
				break;	
		}
	}
	if(is_empty)
		printf("success!\n");
	else
		printf("fail!\n");
}
