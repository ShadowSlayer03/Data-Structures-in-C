// A string is valid if it has no special characters
// Check if given string is valid or not
// ASCII for 'A' = 65
// ASCII for 'Z' = 90
// ASCII for 'a' = 97
// ASCII for 'z' = 122
// ASCII for '0' = 48
// ASCII for '9' = 57

#include<stdio.h>
#include<stdlib.h>

int main()
{
  char name[]="Tharjiun";
  int i,flag=0; //symbol not present
  for(i=0;name[i]!='\0';i++)
    {
      if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
      {
        flag = 1;
        break;
      }
    }
  if(flag)
    printf("String is not valid\n");
  else
    printf("String is valid\n");
  
  return 0;
}
