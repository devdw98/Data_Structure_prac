#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_full();
int is_empty();
int push(element item);
int pop();
int peek();


int main()
{
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",peek());
	printf("%d\n",pop());
	printf("%d\n",pop());
	
	
	return 0;
}

int is_empty(){
	return top==-1;
}
int is_full(){
	return top == MAX_STACK_SIZE -1;
}
int push(element item){
	if(is_full()){
		printf("STACK is full.\n");
		return -1;
	}
	stack[++top] = item;
	return 0;
}

element pop(){
	if(is_empty()){
		printf("STACK is empty.\n");
		exit(1);
	}
	return stack[top--];
}

element peek(){
	if(is_empty()){
		printf("STACK is empty.\n");
		exit(1);
	}
	return stack[top];
}
