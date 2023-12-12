#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct bnode{
    int info;
    struct bnode *left;
    struct bnode *right;

};
struct bnode *root=NULL, *temp=NULL;

struct bnode * insert(struct bnode *root,int data){
    if(root==NULL){
        root= (struct bnode* )malloc(sizeof(struct bnode));
        root->right=NULL;
        root->left=NULL;
        root->info=data;

    }
    else{
        if(data>root->info){
            root->right=insert(root->right,data);
        }
        else{
            root->left=insert(root->left,data);
        }
    }
    return root;
}

void Inorder(struct bnode *root){
    if(root!=NULL){
    Inorder(root->left);
    printf("%d\t",root->info);
    Inorder(root->right);

    }
    
}

void Preorder(struct bnode *root){
    if(root!=NULL){
    printf("%d\t",root->info);
    Preorder(root->left);
    Preorder(root->right);
    }
    
}

void Postorder(struct bnode *root){
    if(root!=NULL){
    Postorder(root->left);
    Postorder(root->right);
    printf("%d\t",root->info);
    }
    
}

struct bnode *Findmin(struct bnode *root){
    if(root==NULL)
        return 0;
    else if(root->left==NULL)    
        return root;

    else 
    return(Findmin(root->left));
}
struct bnode * Delete(struct bnode *root,int data){
    if(root==NULL){
        printf("\n Tree is empty");
        return NULL;
    }
    else if(data<root->info)
    {
        root->left=Delete(root->left,data);
    }
    else if(data>root->info){
        root->right=Delete(root->right,data);
    }
    else if(root->left!=NULL && root->right!=NULL){
        temp=Findmin(root->right);
        root->info=temp->info;
        root->right=Delete(root->right,root->info);
    

    }
    else{
        temp=root;
        if(root->left==NULL)
            root=root->right;
        else if(root->right==NULL)
            root= root->left;
        free(temp);
    }                                                            //   5 20 15 2 30 1 10 8 13 17
return(root);
}



int count(struct bnode *root){
    if(root==NULL)
    return 0;
    return(1+count(root->left)+count(root->right));

}

void search(struct bnode *root,int data){
    if(root==NULL){
        printf("\n Element doesnt exist");
    }
    else if(data==root->info){
        printf("\nElement found in tree");

    }
    else if(data<root->info){
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }
}

void mirroring(struct Node* r)
{
	struct bnode* temp;
	if(r!=NULL)
	{
		mirroring(root->left);
		mirroring(root->right);
		temp = root->left;
		root->left =root->right;
		root->right = temp;
	}


}

int main(){
    int i,n,data,choice,cnt;
    root=NULL;

    do
    {
        printf("\n BST operations");
        printf("\n Enter a choice \n1.)enter a node\t2.)Preorder\t3.)Postorder\t4.)Inorderd\t5.)Delete\t6.)Node count\t7.)Search\t8.)Exit ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d",&data);
            root=insert(root,data);
            break;

            case 2:
            printf("\nPreorder traversal\n");
            Preorder(root);
            printf("\n");
            break;

            case 3:
            printf("\nPostorder traversal\n");
            Postorder(root);
            printf("\n");
            break;

            case 4:
            printf("\nInorder traversal\n");
            Inorder(root);
            printf("\n");
            break;

            case 5:
            printf("Enter node you wanna delete:");
            scanf("%d",&data);
            root=Delete(root,data);
            break;

            case 6:
            cnt=count(root);
            printf("\n The number of nodes is:%d",cnt);
            break;

            case 7:
            printf("\nEnter the data you want to search:");
            scanf("%d",&data);
            search(root,data);
            break;

            case 8:
            exit(0);
            break;

        default:
        printf("\nENTER A VALID CHOICE");   
            break;
        }
    } while (choice!=7);
    return 0;
    
}