#include<stdio.h>
#include<stdlib.h>
typedef struct time
{
    int hour;
    int min;
    int sec;
    struct time *next;
}TIME;

void display(TIME* t1)
{
 printf("time 1 is %d:%d:%d\n",t1->hour,t1->min,t1->sec);
 printf("time 2 is %d:%d:%d",t1->next->hour,t1->next->min,t1->next->sec);
}
int main()
{
 TIME *t1,*t2;
 t1 = (TIME*)malloc(sizeof(TIME));
 t1->hour = 10;
 t1->min = 25;
 t1->sec = 56;
 t1->next = NULL;
 t2 = (TIME*)malloc(sizeof(TIME));
 t2->hour = 11;
 t2->min = 15;
 t2->sec = 25;
 t2->next = NULL;

 t1->next = t2;
 display(t1);
  free(t1);
 free(t2);
 t1 = NULL;
 t2 = NULL;
 return 0;
}

