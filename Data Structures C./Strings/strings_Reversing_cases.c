 //All uppercase letters in a string change to lowercase and vice-versa but symbols should remain the same
// Uppercase  = Lowercase - 32 
// Lowercase = Uppercase + 32
#include<stdio.h>
#include<stdlib.h>

int main()
{
  char name[] = "PrettyAwesomeStuff$#";
  int i;
  for(i=0;name[i]!='\0';i++) //changing upper to lower & vice-versa
{
      if(name[i]>'A' && name[i]<'Z')   //upper case
    {
        name[i]+=32;
    }
    else if(name[i]>'a' && name[i]<'z')
    {
       name[i]-=32;
    }
}
  printf("%s\n",name);
  return 0;
}
