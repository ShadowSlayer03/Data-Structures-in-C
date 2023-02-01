//All the diff ways of declaring and intialising a 2D array
#include<stdio.h>
#include<stdlib.h>

void printMatrix(int** arr,int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
          printf("%d ",arr[i][j]);
        }
      printf("\n");
    }
}
int main()
{
  int i,j;
  //Static way
  int arr[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{12,23,34,45,56}};
 for(i=0;i<3;i++)
    {
      for(j=0;j<5;j++)
        {
          printf("%5d ",arr[i][j]);
        }
      printf("\n");
    }
  // Dynamic methods
  //1.
  int *arr1[3];
  for(i=0;i<5;i++)
    {
      arr1[i] = (int*)malloc(5*sizeof(int));
    }
  printMatrix(&arr1[0],3,5); 
  
  //2.
  int** p;
  p = (int**)malloc(3*sizeof(int*));
  for(i=0;i<5;i++)
    {
      p[i] = (int*)malloc(5*sizeof(int));
    }
  for(i=0;i<3;i++)
    {
      for(j=0;j<5;j++)
        {
          p[i][j] = j;
        }
      printf("\n");
    }
  printMatrix(p,3,5);
  
  return 0;
}