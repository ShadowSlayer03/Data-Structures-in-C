// Improve searching by 2 methods
// 1. Move to Head
// 2. Transposition
// Transposition is hard since we have to move each node
// Move to head/front is better

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct node 
{
  int data;
  struct node *next;
} NODE;
NODE *first = NULL;
int data = 15, i;
void createLL() {
  NODE *temp, *p;
  first = (NODE *)malloc(sizeof(NODE));
  first->data = data;
  first->next = NULL;
  data = data + 10;
  temp = first;

  for (i = 1; i < SIZE; i++) {
    p = (NODE *)malloc(sizeof(NODE));
    p->data = data;
    p->next = NULL;
    temp->next = p;
    temp = p;
    data += 10;
  }
}

void displayLL(NODE *p) {
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
}

int improvedSearch(int key, NODE *p)  // This search finds key and makes it the first node of LL
{
  NODE *q = NULL; // q is 1 step behind p
  if (p == NULL)
    return 0;

  while (p != NULL) 
  {
    if (p->data == key) 
    {
      printf("Key found\n");
      q->next = p->next;
      p->next = first;
      first = p;
      return 0;
    }
    q = p;
    p = p->next;
  }
  printf("Key not found\n");
  exit(0);
}

int main() 
{
  NODE *result;
  createLL();
  displayLL(first);
  improvedSearch(45,first);
  displayLL(first);
  return 0;
}
