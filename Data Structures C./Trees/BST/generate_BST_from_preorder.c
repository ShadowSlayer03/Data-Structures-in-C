#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
}NODE;
NODE* root=NULL;
typedef struct stack
{
    int size;
    int top;
    NODE** S;
}STK;

void push(STK* st,NODE* addr)
{
 if(st->top==st->size-1)
 {
    printf("Stack overflow\n");
    return;
 }
 st->top++;
 st->S[st->top] = addr;
}
NODE* pop(STK* st)
{
    NODE* x;
    if(st->top==-1)
    {
        printf("Stack underflow\n");
        return NULL;
    }
    x = st->S[st->top--];
    return x;
}
int stacktop(STK* st)
{
    if(st->top==-1)
        return INT_MAX;
    else
        return (st->S[st->top])->data;    
}
void generate(int* arr,int n)
{
    int i=0;
    NODE* p,*newnode;

    STK stack;
    stack.size = 20;
    stack.top=-1;
    stack.S = (NODE**)malloc(stack.size*sizeof(NODE*));

    root=(NODE*)malloc(sizeof(NODE));
    root->lchild=root->rchild=NULL;
    root->data = arr[i++];
    p=root;
    while(i<n)
    {
        if(arr[i]<p->data)
        {
            newnode = (NODE*)malloc(sizeof(NODE));
            newnode->lchild=newnode->rchild = NULL;
            newnode->data = arr[i++];
            p->lchild = newnode;
            push(&stack,p);
            p=newnode;
        }
        else
        {
            if(arr[i]>p->data && arr[i]<stacktop(&stack))
            {
                newnode = (NODE*)malloc(sizeof(NODE));
                newnode->lchild=newnode->rchild = NULL;
                newnode->data = arr[i++];
                p->rchild = newnode;
                p = newnode;
            }
            else
                p = pop(&stack);
        }
    }
}
void Inorder(NODE* p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
    
int main()
{
    int size,i;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    int pre[size];
    printf("Enter the preorder values\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&pre[i]);
    }
    generate(pre,size);
    Inorder(root);   // Just to check if BST creation is correct
    return 0;
}
