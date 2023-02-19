#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
  struct Node* lchild;
  int data;
  struct Node* rchild;
}NODE;
typedef struct Queue
{
  int front;
  int rear;
  int size;
  NODE** Q;
}QUEUE;

NODE* root= NULL;
QUEUE* create(int size)
{
  QUEUE* q;
  q = (QUEUE*)malloc(sizeof(QUEUE));
  q->front = q->rear = 0;
  q->size = size;
  q->Q = (NODE**)malloc(q->size*sizeof(NODE*));
  return q;
}
void enqueue(QUEUE* q, NODE* x)
{
  if((q->rear+1)%q->size==(q->front))
  {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear+1)%q->size;
  q->Q[q->rear] = x;
}
NODE* dequeue(QUEUE* q)
{
  NODE* x=NULL;
  if(q->rear==q->front)
  {
    printf("Queue is empty\n");
  }
  else
  {
    q->front = (q->front+1)%q->size;
    x = q->Q[q->front];
  }
  return x;
}
int isEmpty(QUEUE* q)
{
  return q->front==q->rear;
}
void treeCreate()
{
  int a;
  NODE* p;
  QUEUE* q = create(10);
  printf("Enter the root value\n");
  scanf("%d",&a);
  root = (NODE*)malloc(sizeof(NODE));
  root->data = a;
  root->lchild = NULL;
  root->rchild = NULL;
  enqueue(q,root);
  while(!isEmpty(q))
    {
      p = dequeue(q);
      printf("Enter value of left child of %d\n",p->data);
      scanf("%d",&a);
      if(a!=-1)
      {
        NODE* t = (NODE*)malloc(sizeof(NODE));
        t->data = a;
        t->lchild=t->rchild=NULL;
        p->lchild = t;
        enqueue(q,t);
      }
      printf("Enter value of right child of %d\n",p->data);
      scanf("%d",&a);
      if(a!=-1)
      {
        NODE* t = (NODE*)malloc(sizeof(NODE));
        t->data = a;
        t->lchild=t->rchild=NULL;
        p->rchild = t;
        enqueue(q,t);
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
void Preorder(NODE* p)
{
  if(p)
  {
   printf("%d ",p->data);
  Inorder(p->lchild);
  Inorder(p->rchild); 
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
  treeCreate();
  Preorder(root);
  printf("\n");
  Inorder(root);
  printf("\n");
  Postorder(root);
  
  return 0;
}
