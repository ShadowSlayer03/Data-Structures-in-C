#include<stdio.h>
#include<stdlib.h>

int main()
{
  char word[] = "Hello123";
  char word1[] = "Hello";
  int i,j,flag=0;    //string is not same
  for(i=0,j=0;word[i]!='\0'|| word1[j]!='\0';i++,j++)
    {
      if((word[i]=='\0'&&word1[j]!='\0') || (word[i]!='\0'&&word1[j]=='\0'))
      {
        flag =0;
        break;
      }
      if(word[i]==word1[j])
      {
        flag=1;
        continue;
      }
      else{
        flag = 0;
        break;
      }
      
    }
  
  if(flag==0)
  {
    printf("String is not same\n");
  }
  else{
    printf("String is same");
  }
  return 0;
}
