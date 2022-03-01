#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left, *right;
};

struct tree* create();
struct tree* insert(int data);
void inorder(struct tree* root);
void postorder(struct tree* root);
void preorder(struct tree* root);

int main()
{
    struct tree *root = NULL;
    int choice=0, key=0;
    do
    {
        printf("\nEnter choice:\n1. Insert\n2. Traverse\nAny other number to exit.\nEnter Choice : ");
        scanf("%d", &choice);
        if(choice==1)
        {
            printf("\nEnter value to insert for root(-1 for no node) : ");
            scanf("%d", &key);
            root=insert(key);
            printf("BINARY TREE:\n");
            inorder(root);
        }
        else if(choice==2)
        {
            printf("Enter choice of traversal:\n1. Inorder Traversal\n2. Preorder Traversal\n3. Postorder Traversal\nEnter Option : ");
            scanf("%d", &key);
            printf("\nBinary Tree : ");
            if(key==1)
                inorder(root);
            else if(key==2)
                preorder(root);
            else if(key==3)
                postorder(root);
            else
                printf("Invalid Selection");
        }
        else 
        {
            printf("EXIT.");
        }
    }while(choice==1 || choice==2);
    return 0;
}

struct tree* create()
{
    struct tree *newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->left=NULL, newnode->right=NULL;
    return newnode;
}
struct tree* insert(int data)
{
    struct tree *newnode = create();
    int temp=data;
    if(data==-1)
	return 0;
    newnode->data=data;
    
    printf("Enter left child of %d:\n",temp);
    scanf("%d",&data);
    newnode->left=insert(data);
    printf("Enter right child of %d:\n",temp);
    scanf("%d",&data);
    newnode->right=insert(data);
    return newnode;
}

void inorder(struct tree* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct tree* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(struct tree* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}