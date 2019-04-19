#include <stdio.h>

typedef int element;

typedef struct ListNode{
	element data; //??????? ???
	struct ListNode *next;
}ListNode;

ListNode* insert(ListNode *head, ListNode *pre, element value );
ListNode* insert_first(ListNode *head, element value);

ListNode* delete(ListNode *head, ListNode *pre);
ListNode* delete_first(ListNode *head);

ListNode* clear(ListNode *head);
void print_list(ListNode *head);
 
element get_entry(ListNode *head, int pos);
//int is_full(ListNode);
int is_empty(ListNode *head);

int search_list(ListNode *head, element value);


int main(){
	ListNode *head = NULL;
	head = insert_first(head, 5);
	head =insert_first(head, 4);
	head = insert(head, head->next, 3);
	
	print_list(head);
	
	printf("1st entry : %d\n", get_entry(head, 1));
	search_list(head, 5);
	search_list(head, 8);
	
	head = delete_first(head);
	
	print_list(head);
	
	head = insert_first(head,7);
	
	print_list(head);
	
	head = delete(head, head);
	
	print_list(head);
	clear(head);
	print_list(head);
	
}
ListNode* insert(ListNode *head, ListNode *pre, element value ){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	//?????? ???? 
	p->next = pre->next;
	pre->next = p;
	return head;
}
ListNode* insert_first(ListNode *head, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	//?????? ????
	p->next = head;
	head = p;
	return head;
}

ListNode* delete(ListNode *head, ListNode *pre){
	ListNode *deleted;
	if (pre->next ==NULL){
		printf("cannot delete that node!");
		return head; 
	}
	
	deleted = pre->next; //?¯C?? ???? ??? = pre?? ???? ??? 
	pre->next = deleted->next;
	free(deleted);
	return head;
}
ListNode* delete_first(ListNode *head){
	ListNode *deleted;
	deleted = head; //?¯C?? ???? ??? = u??¡Æ ??? = ??? 
	head = deleted->next;
	free(deleted);
	return head;
}

ListNode* clear(ListNode *head){
	head = NULL;
	return head; //?????? ??? ???? 
}
void print_list(ListNode *head){
	ListNode *p;
//	for(int i = 0 ; i< length ; i++)
	for(p = head; p->next != NULL; p = p->next ){
		printf("%d -> ", p->data);
	}
	printf("%d -> ", p->data);
	printf("NULL\n");
}
 
element get_entry(ListNode *head, int pos){
	ListNode* result;
	result = head;
	int i = 0;
	
	for (i= 0; i<pos; i++){
		result = result->next;
	} 
	
	return result->data;
	
}
//int is_full(ListNode);
int is_empty(ListNode *head){
	if (head==NULL){
		return 1; // ??????? ?? 
	} else {
		return 0;  
	}
}
int search_list(ListNode *head, element value){
	ListNode *p;
//	for(int i = 0 ; i< length ; i++)
	for(p = head; p->next != NULL; p = p->next ){
		if (p->data == value){
			printf("%d°ªÀ» Ã£¾Ò½À´Ï´Ù.\n", value);
			return 1;
		}
	}
	if (p->data == value){
			printf("%d°ªÀ» Ã£¾Ò½À´Ï´Ù.\n", value);
			return 1;
	}
	printf("%d°ªÀ» Ã£Áö ¸øÇß½À´Ï´Ù.\n",value);
	return 0;
}





