#include<stdio.h>

int largest(int* a,int* b,int*c)
{
if(*a>*b&&*a>*c)
{
return *a;
}
else if(*b>*c)
{
return *b;
}
else
{
return *c;
}
}
int main()
{
int a,b,c,max;
printf("Enter the numbers:");
scanf("%d%d%d",&a,&b,&c);
max = largest(&a,&b,&c);
printf("Largest number is %d",max);
return 0;
}
