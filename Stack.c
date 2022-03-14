#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 
void push(int data);
void pop();
void isempty();
void isfull();
void display();
void create(int size);
 
int count = 0, size_of;
 
void main()
{
    create(6);
	
	push(10);
	push(20);
	push(30);
	push(40);		
    display();
	
	pop();
	pop();
    
	isempty();
	
	isfull();
	
	display();            
}
 
/* Create empty stack */
void create(int size)
{
	size_of=size;
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}
 
/* Push data into stack */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
}
 
/* Check if stack is empty or not */
void isempty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty ");
}

/* Check if stack is full or not */
void isfull()
{
    if( count==size_of) 
		printf("\n Stack is full");
	else 
		printf("\n Stack is not full");
}













