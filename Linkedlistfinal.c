#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void AddAtFront(int info);
void AddAtEnd(int info);
void DeleteAtFront();
void DeleteAtEnd();
void Display();
void DeleteAtPosition(int position);
int Search(int info);
void InsertAtPosition(int info,int position);
void SearchAndDelete(int info);
int count=0;



struct node{
    int data;
    struct node *next;
};

struct node *head=NULL, *last=NULL, *temp=NULL, *newnode, *p=NULL;

struct node *createnode(int info){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=info;
    newnode->next= NULL;
    return newnode;

}


void AddAtFront(int data){
    newnode= createnode(data);
    count++;
    
    if(head==NULL){
        head = newnode;
        last= newnode;
    }
    else{
        newnode->next= head;
        head=newnode;
    }
}

void AddAtEnd(int info){
    newnode= createnode(info);
    count++;
    if(head==NULL){
        head = newnode;
        last= newnode;
    }
    else{
        last->next= newnode;
        last=newnode;
    }
}

void DeleteAtFront(){
    temp= head;
    if(head==NULL){
        printf("\nList is empty");
    }
    else{
        head=head->next;
        free(temp);
        count--;

    }

}

void DeleteAtEnd(){
    
    if(head==NULL){
        printf("\nList is empty");
    }
    else if(head->next==NULL){
        head=NULL;
        count--;
    }
    else{
        temp= head;
        while(temp->next!=last){
            temp=temp->next;
        }
        printf("\nElement gonee %d",last->data);
        free(last);
        temp->next=NULL;
        last =temp;
        count --;
    }
}

void InsertAtPosition(int data,int position){
    newnode= createnode(data);
    if(position ==1){
        AddAtFront(data);
    }
    else if(position==(count+1)){
        AddAtEnd(data);
    }
    else if(position>(count+1)){
        printf("\nEnter a valid position");
    }
    else{
        temp=head;
        for(int i=1;i<(position-1);i++){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=temp->next;   
        count++;
    }
}

int Search(int info){
    if(head==NULL){
        return 0;
    }
    else{
        int flag=0;
        int index=0;
        temp=head;
        while(temp!=NULL){
            if(temp->data==info){
                flag=1;
                return index+1;
            }
            else{
                temp=temp->next;
                index++;
            }
        }
        if(flag==0){
            return 0;
        }
    }

}

void SearchAndDelete(int info){
    if(head==NULL){
        printf("\nList is empty");
    }
    else{
        int pos=Search(info);
        if(pos==1){
            DeleteAtFront();
        }
        else if(pos==count){
            DeleteAtEnd();
        }
        else{
            temp=head;
            for(int i=1;i<pos;i++){
                p=temp;
                temp=temp->next;
            }
            p->next=temp->next;
            free(temp);
            count--;
        }
    }
}
void DeleteAtPosition(int position){
     if(position ==1){
        DeleteAtFront();
    }
    else if(position==(count+1)){
        DeleteAtEnd();
    }
    else if(position>(count+1)){
        printf("\nEnter a valid position");
    }
    else{
            temp=head;
            for(int i=1;i<position;i++){
                p=temp;
                temp=temp->next;
            }
            p->next=temp->next;
            free(temp);
            count--;

    }
}
void Display()
{
    printf("\n Total Nodes in the list: %d \n",count);
    if(head==NULL)
    {
        printf("\n List is Empty");

    }
    else{
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int data,choice,position;
    do
    {
        printf("\n ***LINKED LIST***");
        printf("\n 1.)AddatBegin 2.)AddAtEnd 3.)DeleteAtBegin"
         "\n4.)DeleteAtEnd 5.)InsertAtPosition 6.)Search 7.)Delete At Postion 8.)Search and Delete 9.)exit");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("\n Enter the data you want to add");
            scanf("%d",&data);
            AddAtFront(data);
            Display();
            break;

            case 2:
            printf("\n Enter the data you want to add");
            scanf("%d",&data);
            AddAtEnd(data);
            Display();
            break;

            case 3:
            DeleteAtFront();
            Display();
            break;

            case 4:
            DeleteAtEnd();
            Display();
            break;

            case 5:
            printf("\n Enter the data you want to add");
            scanf("%d",&data);
            printf("\nEnter the position at which you want to insert: ");
            scanf("%d",&position);
            InsertAtPosition(data,position);
            Display();
            break;

            case 6:
            printf("\n Enter the data you want to search");
            scanf("%d",&data);
            position=Search(data);
            if(position==0){
                printf("\nNot Found");
            }
            else{
                printf("\nElement found at position: %d",position);
            }
            break;

            case 7:
            printf("\nEnter the position at which you want to delete: ");
            scanf("%d",&position);
            DeleteAtPosition(position);
            Display();
            break;

            case 8:
            printf("\n Enter the data you want to search and delete: ");
            scanf("%d",&data);
            SearchAndDelete(data);
            Display();
            break;

            case 9:
            exit(0);
            break;

            default:
            printf("\nEnter a valid choice");

        }
    } while (choice!=9);
    
   
    

    return 0;
}
