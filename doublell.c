#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct node *left;
    struct node *right;
};

struct Node *node,*head= NULL, *last= NULL, *temp, *p , *q;
void AddAtStart(int info);
void AddAtEnd(int info);
void DeleteAtStart();
void DeleteAtEnd();
void AddAtPosition(int info);
int Search(int info);
void DisplayF();
void DisplayB();
int count=0;


int main(){
    int data,choice,loc;
    do
    {
        printf("\n Enter your choice 1).AddAtStart\t2.)AddAtEnd\t3.)DeleteAtEnd\t4.)DeleteAtEnd\t5.)DisplayFront\t6.)DisplayBack\t7.)Search\t8.)Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\n Enter your data:");
            scanf("%d",&data);
            AddAtStart(data);
            break;

            case 2:
            printf("\n Enter your data:");
            scanf("%d",&data);
            AddAtEnd(data);
            break;

            case 3:
            DeleteAtStart();
            break;

            case 4:
            DeleteAtEnd();
            break;

            case 5:
            DisplayF();
            break;

            case 6:
            DisplayB();
            break;

            case 7:
            printf("\nEnter the data you want to search:");
            scanf("%d",&data);
            loc=Search(data);
            if(loc==-1)
            printf("\nData not found in list");
            
            else
            printf("\nData found at %d Positon",loc);
            break;
        
            case 8:
            exit(0);
            break;

            default:
            printf("\n Enter a valid choice");

        }
    } while (choice!=8);
    
return 0;
}


struct Node * createnode(int info)
{
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->data=info;
    node->left= NULL;
    node-> right= NULL;
    count+=1;
    return node;
}

void AddAtStart(int info)
{
    node= createnode(info);
if(head== NULL){
    head= node;
    last= node;
    head->left=NULL;
    head->right=NULL;
    
}
else{
    head->left=node;
    node->right= head;
    head= node;
    head->left= NULL;

}
}

void DisplayF(){
    if(head== NULL){
        printf("\n List is empty");
    }
    else{
        temp=head;
    while(temp!= NULL){
        printf("%d ->",temp->data);
        temp=temp->right;

    }
    
    }

}
void DisplayB()
{
    if(head== NULL){
        printf("\n List is empty");
    }
    else{
        temp=last;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->left;
        }
    }
}
void AddAtEnd(int info)

{ 
    node= createnode(info);
    if(head==NULL){
        head=node;
        last= node;
        head->left=NULL;
        head->right= NULL;

    }
    else{
        last->right=node;
        node->left=last;
        last=node;
        last->right= NULL;
    }
}

void DeleteAtStart(){
    if(head== NULL){
        printf("\n List is empty");
    }
    else{
        temp = head;
        head= head->right;
        head->left=NULL;
        free(temp);
    }
}

void DeleteAtEnd()
{
    if(head== NULL){
        printf("\n List is empty");
    }
    else{
        temp=last;
        last=last->left;
        last->right=NULL;
        free(temp);
    }
}

int Search(int info){
    int position=0;
    if(head== NULL){
        return -1;
    }
    else{
        
    temp=head;
    while(temp!=NULL){
        if(temp->data== info){
            return position+1;
           
            
        }
        
        temp= temp->right;
        position=position+1;
       
    }
    }
    return -1;
}
void AddAtPosition(int info){
    int position,i=0;
    printf("\nEnter the position:");
    scanf("%d",&position);
    if(info==1){
        AddAtStart(info);
    }
    else if(position= (count+1)){
        AddAtEnd(info);
    }
    else{
        node=createnode(info);
        temp=head;
        p=head;
        for(i=1;i<position;i++){
            p=temp;
            temp=temp->right;
        }
        p->right = node;
        node->right = temp;
        temp->left= node;

    }
}