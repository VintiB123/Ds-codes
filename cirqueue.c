#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 6
int rear=-1,front=-1,data;
int queue[N];
void EnQueue(int data);
void DeQueue();
void Display();

int main()
{
    int choice,data;
    //clrscr();
    do
    {
        printf("\n ****CIRCULAR QUEUE****");
        printf("\n 1.)ENQUEUE \t 2.)DEQUEUE \t  3.)EXIT ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("\nenter the data you want to enqueue");
            scanf("%d",&data);
            EnQueue(data);
            Display();
            break;

            case 2:
            DeQueue();
            Display();
            break;

            case 3:
            exit(0);
            break;

            default:
            printf("\n Enter valid choice");
            break;





        }
    } while (choice!=3);
    
return 0;

}

void EnQueue(int data)
{
    if(rear==-1 && front==-1)
    {
        rear=0;
        front=0;
        queue[rear]=data;

    }
    else if((rear+1)%N==front) 
    {
        printf("\n Queue is full");
    }

    else
    {
        rear=(rear+1)%N;
        queue[rear]=data;
    }


}

void DeQueue()
{
    if(rear==-1 && front==-1)
    {
        printf("\n Queue is empty");
    }
    else if(front==rear)
    {
        printf("\nDeleted Element of the queue",queue[front]);
        front=-1;
        rear=-1;
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n Deleted Element of the Queue",queue[front]);
        front=(front+1)%N;
    }
}

void Display()
{
    int i;
    printf("\n");
    if(front==-1 && rear==-1)
    {
         printf("\n Queue is empty");
    }
       
    else
    {
        if(front>rear)
        {
            for(i=front;i<N;i++)
            {
                printf("\t%d",queue[i]);
            }
            for(i=0;i<front;i++)
            {
                printf("\t%d",queue[i]);
            }
        }
        else
        {
            for(i=front;i<=rear;i++)
            {
                printf("\t%d",queue[i]);
            }
        }
    }    
}


