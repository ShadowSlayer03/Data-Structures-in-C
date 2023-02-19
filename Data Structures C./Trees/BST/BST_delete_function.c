// Delete a node in BST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  struct node* lchild;
  int data;
  struct node* rchild;
}NODE;
NODE* root= NULL;

int Height(NODE* p)
{
  if(p==NULL)
    return 0;
  int x,y;
  x = Height(p->lchild);
  y = Height(p->rchild);
  if(x>y)
    return x+1;
  else
    return y+1;
}
NODE* InsertRec(NODE* p,int key)
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
  if(p->data<key)
    p->rchild = InsertRec(p->rchild,key);
  else if(p->data>key)
    p->lchild = InsertRec(p->lchild,key);
  
    return p;
}
NODE* InPre(NODE* p)        // preorder successor 
{
  while(p && p->rchild)
    {
      p=p->rchild;
    }
  return p;
}
NODE* InSucc(NODE* p)      // inorder successor 
{
  while(p && p->lchild)
    {
      p=p->lchild;
    }
  return p;
}
NODE* Delete(NODE* p,int key)
{
  NODE* q;
  
  if(p==NULL)
    return NULL;
  if(p->lchild==NULL && p->rchild==NULL)
  {
    if(p==root)
      root = NULL;
    free(p);
    return NULL;
  }
  if(key<p->data)
    p->lchild = Delete(p->lchild,key);
  else if(key>p->data)
    p->rchild = Delete(p->rchild,key);
  else
  {
    if(Height(p->lchild)>Height(p->rchild))
    {
      q = InPre(p->lchild);
      p->data = q->data;
      p->lchild = Delete(p->lchild,q->data);
    }
    else
    {
      q = InSucc(p->lchild);
      p->data = q->data;
      p->rchild = Delete(p->rchild,q->data);
    }
  }
  return p;
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
int i=5,key;
  while(i!=0)
    {
      printf("Enter the value\n");
      scanf("%d",&key);
      InsertRec(root,key);
      i--;
    }
  Inorder(root);
  printf("\n");
  Delete(root,23);
  Inorder(root);
  return 0;
}
