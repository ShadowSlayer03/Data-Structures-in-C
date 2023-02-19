// Binary Search Tree - Recursive Insert
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  struct Node* lchild;
  int data;
  struct Node* rchild;
}NODE;
NODE* root=NULL;

NODE* insert(NODE* p,int key)
{
  NODE* newnode;
  if(p==NULL)
  {
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->lchild = newnode->rchild = NULL;
    newnode->data = key;
    if(root==NULL)
    root = newnode;
    return newnode;
  }
  if(key<p->data)
    p->lchild = insert(p->lchild,key);
  else if(key>p->data)
    p->rchild = insert(p->rchild,key);

  return p;
}
void Preorder(NODE* p)
{
  if(p)
  {
    printf("%d ",p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
  }
}
int main()
{
  int i=5,val;
  NODE* temp;
  while(i!=0)
    {
      printf("Enter the key\n");
      scanf("%d",&val);
      insert(root,val);
      i--;
    }
  Preorder(root);
  return 0;
}
