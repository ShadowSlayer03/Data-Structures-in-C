// Convert a string from uppercase to lowercase and vice-versa
// Difference in ASCII codes of upper and lower is 32
// Uppercase  = Lowercase - 32 
// Lowercase = Uppercase + 32
#include<stdio.h>
#include<stdlib.h>

int main()
{
  char name[] = "ARJUN";
  char name1[] = {'a','r','j','u','n','\0'};
  int i;
  for(i=0;name[i]!='\0';i++) //changing upper to lower
    {
      name[i]+=32;
    }
  for(i=0;name1[i]!='\0';i++) //changing lower to upper 
    {
      name1[i]-=32;
    }
  printf("%s\n",name);
  printf("%s",name1);
  return 0;
}