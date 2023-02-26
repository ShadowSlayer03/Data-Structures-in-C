// Height, Total Count, Leaf nodes Count and InternalNodes Count in a Tree
#include<stdio.h>
#include<stdlib.h>

int count(NODE* p)
{
  if(p)
    return count(p->lchild)+count(p->rchild)+1;
  else
    return 0;
}
int CountLeaf(NODE* p)  // Count leaf nodes or external nodes
{
  if(p==NULL)
    return 0;
  if(p->lchild==NULL && p->rchild==NULL)
    return CountLeaf(p->lchild)+CountLeaf(p->rchild)+1;
  else
    return CountLeaf(p->lchild)+CountLeaf(p->rchild);   
}
int CountInternal(NODE* p)    // Internal means nodes with degree 1 and 2
{
  if(p==NULL)
    return 0;
  if(p->lchild!=NULL || p->rchild!=NULL)
    return CountLeaf(p->lchild)+CountLeaf(p->rchild)+1;
  else
    return CountLeaf(p->lchild)+CountLeaf(p->rchild);   
}
int height(NODE* p)
{
  int x=0,y=0;
  if(!p)
    return 0;
  else
  {
    x = height(p->lchild);
    y = height(p->rchild);
    if(x>y)
      return x+1;
    else
      return y+1;
  }
}
int main()
{
  printf("%d\n",count(root));
  printf("%d\n",height(root));
  printf("%d\n",CountLeaf(root));
  printf("%d\n",CountInternal(root));
  return 0;
}
