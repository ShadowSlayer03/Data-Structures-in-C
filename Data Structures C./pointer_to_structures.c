#include<stdio.h>
#include<stdlib.h>
int main()
{
  typedef struct student
  {
    int s;
    int y;
    float d;
    double t;
  }STUDENT;
  //printf("%lu\n",sizeof(STUDENT));
  STUDENT s1 = {5,9,6.8,7.66};  // stack memory allocation
  STUDENT *p = &s1;
  printf("The value of s in s1 is %d\n",(*p).s);  
  // *p.s wont work because dot has more precedence over star. So we need brackets to dereference the pointer and access values
  printf("The value of s in s1 is %d\n",p->s);
  
  STUDENT *s2 = (STUDENT*)malloc(sizeof(STUDENT));  //heap or dynamic memory allocation
  s2->s = 78;
  s2->y = 90;
  s2->d = 7.6;
  s2->t = 7.98;
  printf("%d %d %.2f %.2lf",s2->s,s2->y,s2->d,s2->t);
  return 0;
}