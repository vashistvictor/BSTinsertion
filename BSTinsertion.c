#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;

struct node * create(int value)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void preorderdisplay(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorderdisplay(root->left);
        preorderdisplay(root->right);
    }
}

void insert(struct node *root,int value)
{
    struct node *prev,*new;
    new = create(value);
    while(root!=NULL)
    {
        prev = root; //to keep track of previous element of root node
        if(root->data > value)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if(prev->data > value)
    {
        prev->left = new;
    }
    else if(prev->data < value)
    {
        prev->right = new;
    }
}

int main()
{
    int n,value;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    scanf("%d",&value); //for 1st value
    root = create(value);
    for(int i=1;i<n;i++) //loop for the remaining values
    {
        scanf("%d",&value);
        insert(root,value);
    }
    preorderdisplay(root); //preorder traversal display 
    return 0;
}
