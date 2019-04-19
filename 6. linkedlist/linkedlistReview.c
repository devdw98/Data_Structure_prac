#include <stdio.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

void init();
ListNode* insert(ListNode *head, ListNode* pre, element item);
ListNode* insert_first(ListNode *head, element item);
ListNode* delete(ListNode *head, ListNode *pre);
ListNode* delete_first(ListNode *head);
ListNode* clear(ListNode* head);
element get_entry(ListNode* head, int pos);
ListNode* get_length(ListNode* head);
int is_empty(ListNode* head);
void print_list(ListNode* head);

int main()
{
	ListNode *head = NULL;
	int i;
	head = insert_first(head, 5);
	head =insert_first(head, 4);
	head =insert_first(head, 3);
//	head = insert(head, head->next, 3);
	
	print_list(head);
	
	printf("1st entry : %d\n", get_entry(head, 1));
//	search_list(head, 5);
//	search_list(head, 8);
	
	head = delete_first(head);
	
	print_list(head);
	
	head = insert_first(head,7);
	
	print_list(head);
	
	head = delete(head, head);
	
	print_list(head);
	
	clear(head);
	print_list(head);
	
	for ( i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}

ListNode* insert(ListNode *head, ListNode *pre, element item){
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_first(ListNode *head, element item){
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert_last(ListNode *head, element item){
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	return head;
}
ListNode* delete(ListNode *head, ListNode *pre){
	ListNode *removed;
	element value;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
ListNode* delete_first(ListNode *head){
	ListNode* removed;
	if(head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* clear(ListNode* head){
	head =NULL;
	return head;
}
element get_entry(ListNode* head, int pos){
	ListNode* entry;
	int i;
	for(i=0;i<pos;i++){
		entry = head->link;
		if(entry == NULL){
			printf("NULL\n");
			return 0;
		}	
	}
	return entry->data;
}
ListNode* get_length(ListNode* head);
int is_empty(ListNode* head){
	return head->link == NULL;
}
void print_list(ListNode* head){
	ListNode *p;
	for(p=head;p!=NULL;p=p->link)
		printf("%d->",p->data);
	printf("NULL\n");
}
