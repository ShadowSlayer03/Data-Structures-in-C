// Binary Search Tree and Inorder, Preorder and Postorder Traversals
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  struct Node* lchild;
  int data;
  struct Node* rchild;
}NODE;
NODE* root=NULL;

void Insert(int key)
{
  NODE* newnode,*r,*t;
  t = root;
  if(root==NULL)
  {
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = key;
    newnode->lchild = newnode->rchild = NULL;
    root = newnode;
    return;
  }
  while(t!=NULL)
    {
      r=t;   // r is a trailing pointer of t
      if(key<t->data)
        t = t->lchild;
      else if(key>t->data)
        t = t->rchild;
      else
        return;
    }
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = key;
    newnode->lchild = newnode->rchild = NULL;

  if(key<r->data) r->lchild = newnode;
  else r->rchild = newnode;
}
NODE* Search(int key)
{
  NODE* t = root;
  while(t!=NULL)
  {
    if(t->data==key)
      return t;
    else if (key<t->data)
      t = t->lchild;
    else
      t = t->rchild;
  }
  return NULL;
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
void Preorder(NODE* p)
{
  if(p)
  {
  printf("%d ",p->data);
  Preorder(p->lchild);
  Preorder(p->rchild);
  }
}
void Postorder(NODE* p)
{
  if(p)
  {
    Postorder(p->lchild);
  Postorder(p->rchild);
  printf("%d ",p->data);
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
      Insert(val);
      i--;
    }
  Inorder(root);
  printf("\n");
  Preorder(root);
  printf("\n");
  Postorder(root);
  printf("\n");
  temp = Search(21);
  if(temp)
    printf("Present\n");
  else
    printf("Not present\n");
  return 0;
}
