#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5
void push(int data);
void pop();
void stackTop();
void display();
int tos=-1,stack[MAX],i=0;

int main()
{
    int data=0,choice;
    

    do
    {
	printf("\n ***Stack Operations***");

	printf("\n 1.)PUSH \n 2.)POP \n 3.)StackTop \n 4.)Display \n 5.)Exit");
	printf("\n Enter the choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
	    printf("\n Enter Data to add into stack:");
	    scanf("\n %d",&data);
	    push(data);
	    display();
	    break;

	    case 2:
	    pop();
	    //("\n After popping element the stack is:");
	    display();
	    break;

	    case 3:
	    stackTop();
	    display();
	    break;

	    case 4:
	    display();
	    break;

	    case 5:
	    exit(0);
	    break;

	    default:
	    printf("\n Please enter a valid choice");
	    break;
	}
    } while (choice!=5);

return 0;

}

void push(int data)
{
    if(tos==(MAX-1))
	printf("\n Stack is full cannot push element");
    else
    {
	tos++;
	stack[tos]=data;
	printf("\n After pushing the data the stack is:");
    }

}

void pop()
{
    if(tos==-1)
    {
	printf("\n Cannot pop Stack is empty");
    }
    else
    {
	printf("\n Element %d has been Popped:",stack[tos]);
	tos--;
    }
}

void stackTop()
{

    if(tos==-1)
    {
	printf("\n No stacktop as stack is empty");

    }
    else
    {
	printf("Element at the top of the Stack is: %d",stack[tos]);
    }
}

void display()
{
    for(i=tos;i>=0;i--)
    {
        printf("\n \t \t %d",stack[i]);
        printf("\n \t \t______");
    }
}
