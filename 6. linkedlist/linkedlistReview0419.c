#include <stdio.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

ListNode* insert(ListNode* head, ListNode* pre, element item);
//ListNode* insert_last(ListNode* head, element item);
ListNode* insert_first(ListNode* head, element item);
ListNode* delete(ListNode* head, ListNode* pre);
ListNode* delete_first(ListNode* head);
int clear(ListNode* head);
element get_entry(ListNode* head, element item);
int get_length(ListNode* head);
int is_empty(ListNode* head);
//int is_full(ListNode* head);
void print_list(ListNode* head);
ListNode* concat_list(ListNode* head1, ListNode* head2);

int main()
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	int i;
	for(i=0;i<5;i++){
		head1 = insert_first(head1, i);
		print_list(head1);
	}
	printf("\n");
	for(i=0;i<3;i++){
		head2 = insert_first(head2, i);
		print_list(head2);
	}
	printf("\n");
			print_list(head1);
			print_list(head2);
	printf("\n");
	head1 = concat_list(head1, head2);
	print_list(head1);
//	clear(head);
//	print_list(head);
	return 0;
}
ListNode* insert(ListNode* head, ListNode* pre, element item){
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_first(ListNode* head, element item){
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
ListNode* delete(ListNode* head, ListNode* pre){
	ListNode* p = pre->link;
	pre->link = p->link;
	free(p);
	return head;
}
ListNode* delete_first(ListNode* head){
	ListNode* p;
	if(head == NULL) return NULL;
	p = head;
	head = p->link;
	free(p);
	return head;
}
int clear(ListNode* head){
	ListNode* h;
	if(head == NULL){
		printf("List is NULL.\n");
		return 0;
	}
	for(h=head; h !=NULL; h = h->link){
	//	head = h->link;
		free(h);
	}
	printf("List is clear.\n");
	return 0;
	
}
element get_entry(ListNode* head, element item){
	ListNode* p;
	for(p=head; p!=NULL; p=p->link){
		if(item == p->data){
			printf("%d is here.\n",item);
			return 0;
		}
	}
	printf("%d is not here.\n",item);
}
int get_length(ListNode* head){
	ListNode* h = head;
	int length=0;
	while(h->link !=NULL){
		length++;
	}
	return length;
}
int is_empty(ListNode* head){
	if(head == NULL) return 1;
	return 0;
}
void print_list(ListNode* head){
	ListNode* h;
	for(h = head; h!=NULL; h = h->link){
		printf("%d -> ",h->data);
	}
	printf("NULL\n");
}
ListNode* concat_list(ListNode* head1, ListNode* head2){
	if(head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	else{
		ListNode* p = head1;
		while(p->link!=NULL)
			p=p->link;
		p->link = head2;
		return head1;
	}
}
