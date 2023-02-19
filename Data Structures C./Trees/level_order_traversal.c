// Level Order Traversal
typedef struct node
{
  struct node* lchild;
  int data;
  struct node* rchild;
}NODE;
typedef struct queue
{
  int front;
  int rear;
  NODE** Q;
}QUEUE;
void LevelOrder(NODE* p)
{
  QUEUE q;
  printf("%d",p->data);
  enqueue(&q,p);
  while(!isEmpty(&q))
    {
      NODE* p = dequeue(&q);
      if(p->lchild)
      {
        printf("%d",p->lchild->data);
        enqueue(&q,p->lchild);
      }
      if(p->rchild)
      {
        printf("%d",p->rchild->data);
        enqueue(&q,p->rchild);
      }
    }
}
