#include <stdio.h>
#include <stdlib.h> 

struct node{
	int data;
	struct node * next;
}*head;
void display (struct node *);
void insert(int data);
void deletelast();
void deletefirst();

int main(){
	
	
	struct node * one = (struct node*)malloc(sizeof(struct node));
	struct node * two = (struct node*)malloc(sizeof(struct node));
	
	one->data=1;
	two->data=2;

	head=one;
	one->next=two;
	two->next=NULL;
	insert(3);
	display(head);
	deletelast();
	deletefirst();
	display(head);
	return 0;
}

void display (struct node * p){
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
	}
}
void insert(int data){
	struct node * p=(struct node*)malloc(sizeof(struct node));
	p->data = data;
	
	if(head==NULL) {head=p;p->next=NULL;}
	else {p->next=head; head=p; }
}
void deletefirst(){
	
	if(head== NULL) return ;
	else head=head->next;
}
void deletelast(){
	struct node * p=head;
	if(p== NULL) return ;
	else if(p->next ==NULL) {
		head =NULL;
	}
	else {
		while (p->next->next!=NULL) p=p->next;
		p->next=NULL;
	}
}