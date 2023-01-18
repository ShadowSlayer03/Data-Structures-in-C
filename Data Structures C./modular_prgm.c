//Modular program to find area and perimeter of rect
#include<stdio.h>

typedef struct rectangle
{
  int length;
  int breadth;
}RECT;

int area(int l,int b)
{
  return l*b;
}
int perimeter(int l,int b)
{
  return 2*(l+b);
}
int main()
{
  RECT r;
  printf("Enter the length of the rectangle\n");
  scanf("%d",&r.length);
  printf("Enter the breadth of the rectangle\n");
  scanf("%d",&r.breadth);
  printf("The area of the rectangle is %d\n",area(r.length,r.breadth));
  printf("The perimeter of the rectangle is %d",perimeter(r.length,r.breadth));
  return 0;
}