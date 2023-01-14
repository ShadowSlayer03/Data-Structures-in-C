#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
  int size;
  int front;
  int rear;
  int* Q;
}QUEUE;

QUEUE* create(int size)
{
  QUEUE* q;
  q = (QUEUE*)malloc(sizeof(QUEUE));
  q->size = size;
  q->front=-1;
  q->rear=-1;
  q->Q = (int*)malloc(q->size*sizeof(int)); 
  return q;
}
void enqueue(QUEUE* q,int element)
{
  if(q->rear==q->size-1)
  {
    printf("Queue is full\n");
    return;
  }
  q->rear++;
  q->Q[q->rear] = element;
}
int dequeue(QUEUE* q)
{
  int x=-1;
  if(q->rear==q->front)
  {
    printf("Queue is empty\n");
    return;
  }
  q->front++;
  x = q->Q[q->front];
  return x;
}
void display(QUEUE* q)
{
  int i;
  if(q->front==-1 && q->rear==-1)
  {
    printf("No elements in queue to display\n");
    return;
  }
  for(i=q->front+1;i<=q->rear;i++)
    {
      printf("%d ",q->Q[i]);
    }
  printf("\n");
}
int First(QUEUE* q) //prints first element of the queue
{
  if(q->front==-1&& q->rear==-1)
    printf("No elements in the queue\n");
  else
  {
    return q->Q[q->front+1];
  }
}
int Last(QUEUE* q) //prints last element of the queue
{
  if(q->front==-1&&q->rear==-1)
    printf("No elements in the queue\n");
  else
  {
    return q->Q[q->rear];
  }
}
int isEmpty(QUEUE* q)
{
  if(q->front==-1 && q->rear==-1)
    return 1;
  else 
    return 0;
}
int main()
{
  int size,result,i;
  printf("Enter the size of the queue\n");
  scanf("%d",&size);
  QUEUE* qu = create(size);
  enqueue(qu,34);
  enqueue(qu,45);
  enqueue(qu,56);
  enqueue(qu,78);
  enqueue(qu,89);
  enqueue(qu,90);
  enqueue(qu,95);
  display(qu);
  
  result = isEmpty(qu);
  if(result) printf("Queue is empty\n");
  else printf("Queue has elements\n");
  i = First(qu);
  printf("%d\n",i);
  i = Last(qu);
  printf("%d\n",i);
  free(qu);
  return 0;
}