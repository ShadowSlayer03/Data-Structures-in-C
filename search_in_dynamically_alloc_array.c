#include<stdio.h>
#include<stdlib.h>
int main()
{
int *arr;
int size,i;
printf("Enter the no of elements in the array\n");
scanf("%d",&size);
arr = (int*)malloc(sizeof(int)*size);
printf("Enter the elements of the array\n");
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
int element;
printf("Enter the element to be searched\n");
scanf("%d",&element);
for(i=0;i<size;i++)
{
if(arr[i]==element)
{
printf("The element %d  is present at position %d",element,i+1);
exit(0);
}
}
printf("The element is not present in the array\n");
free(arr);
arr = NULL;
return 0;
}
