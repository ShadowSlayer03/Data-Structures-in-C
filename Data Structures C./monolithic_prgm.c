//Monolithic program to find area and perimeter of rect
#include<stdio.h>

typedef struct rectangle
{
  int length;
  int breadth;
}RECT;

int main()
{
  RECT r;
  printf("Enter the length of the rectangle\n");
  scanf("%d",&r.length);
  printf("Enter the breadth of the rectangle\n");
  scanf("%d",&r.breadth);
  printf("The area of the rectangle is %d\n",r.length*r.breadth);
  printf("The perimeter of the rectangle is %d",2*(r.length+r.breadth));
  return 0;
}