*******
// Create BST
// Inorder,Preorder, Postorder Traversals
// Search for a node
// Count leaf nodes
// Print array Paths from root to leaf
******
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  struct node* lchild;
  int data;
  struct node* rchild;
}NODE;
NODE* root=NULL;
void Insert(NODE* p,int key)
{
  NODE* r=NULL,*newnode;
  while(p!=NULL)
    {
      r = p;
      if(key==p->data)
        return;
      else if(key<p->data)
        p = p->lchild;
      else
        p = p->rchild;
    }
  newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = key;
  newnode->lchild = newnode->rchild = NULL;
  if(root==NULL)
  {
    root = newnode;
    return;
  }
  if(newnode->data<r->data)
    r->lchild = newnode;
  else
    r->rchild = newnode;
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
int CountLeaf(NODE* p)
{
 if(p==NULL)
   return 0;
  if(p->lchild==NULL && p->rchild==NULL)
    return CountLeaf(p->lchild)+CountLeaf(p->rchild)+1;
  else
    return CountLeaf(p->lchild)+CountLeaf(p->rchild);
}
void printArray(int* paths,int pathLen)
{
  int i;
  static int j=1;   // j should be updated as 1,2,3,4.....
  printf("Path %d: ",j);
  j++;
  for(i=0;i<pathLen;i++)
    {
      printf("%d",paths[i]);
      if(i!=pathLen-1)     //arrow shouldn't be printed at the end
        printf("->");    
    }
  printf("\n");
}
void printPathsRec(NODE* p,int pathLen)
{ 
  static int paths[20];   // so that it isn't reinitialised every recursive call
  if(p==NULL)
    return;

  paths[pathLen] = p->data;
  pathLen++;

  if(p->lchild==NULL && p->rchild==NULL)
    printArray(&paths[0],pathLen);

  else
  {
    printPathsRec(p->lchild,pathLen);
    printPathsRec(p->rchild,pathLen);
  }
}
int main()
{
  RecInsert(root,45);
  RecInsert(root,67);
  RecInsert(root,3);
  RecInsert(root,1);
  RecInsert(root,23);
  RecInsert(root,56);
  RecInsert(root,98);
  Inorder(root);
  printf("\n");
  printf("No of leaf nodes are %d\n",CountLeaf(root));
  printPathsRec(root,0);
  return 0;
}
