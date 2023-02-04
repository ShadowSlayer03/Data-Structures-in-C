//Reverse string without an extra string 
#include<stdio.h>
#include<stdlib.h>

int main()
{
  char name[] = "arjun";
  char t;
  int i,j;
  
  for(j=0;name[j]!='\0';j++);
  
  for(i=0;i<j;i++,j--)
    {
      t = name[i];
      name[i] = name[j-1];
      name[j-1] = t;
    }
  
  printf("%s",name);
  return 0;
}
