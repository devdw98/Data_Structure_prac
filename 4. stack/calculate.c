#include <stdio.h>

#define MAX_LEN 5
typedef int element;
typedef struct{
	element* data;
	int capacity; //현재위치 
	int top;
}Stack;

int calculate(Stack* s, const char* ch);
int main()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = calculate(s,"82/3-32*+");
	printf("결과값은 %d\n", result);
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
int calculate(Stack* s, const char* ch){
	create(s);
	int first, second;
	int result = 0;
	int i, len = strlen(ch);
	for(i=0;i<len;i++){
		if(ch[i]!='+' && ch[i]!='-'&& ch[i]!='*'&&ch[i]!='/')
			push(s,ch[i]-'0');
		else{
			second = pop(s);
			first = pop(s);
			switch(ch[i]){
			case '+':
				push(s,first+second);
				break;				
			 case '-': 
				push(s,first - second);
				break;			 
			 case '*':
				push(s,first*second);
				break;	
			 case '/':			 	
				push(s,first/second);
				break;
			}			
		}
	}
	return pop(s);
}
