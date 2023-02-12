// Anagram means same letters but in a different arrangement
// METHOD 1: Check if each element of a string is in other
// METHOD 2: By using an array table
#include<stdio.h>
#include<stdlib.h>

void checkAnagrambyLoops(char* name1,char* name2)
{
  int flag=1,i,j; 
  for(i=0;name1[i]!='\0';i++);
  for(j=0;name2[j]!='\0';j++);
  if(i!=j)
  {
    printf("Not an anagram");
    exit(0);
  }
  for(i=0;name1[i]!='\0';i++)
    {
      for(j=0;name2[j]!='\0';j++)
        {
          if(name1[i]==name2[j])
            break;
        }                                                            
      if(name2[j]=='\0')
      {
        flag = 0;
        break;
      }
      else
      {
       flag = 1;
       continue; 
      }
    }
  if(flag==0)
    printf("Not an anagram");
  
  else
    printf("It is an anagram");
}
void checkAnagrambyArrayTable(char* name1,char* name2)
{
  int i,arr[26]={0};
  for(i=0;name1[i]!='\0';i++)
    {
      arr[name1[i]-'a']++;
    }
  for(i=0;name2[i]!='\0';i++)
    {
      arr[name2[i]-'a']--;
    }
  for(i=0;i<26;i++)
    {
      if(arr[i]!=0)
      { 
        printf("Not an anagram\n");
        exit(0);
      }
    }
  printf("It is an anagram\n");
}
int main()
{
  char name1[] = "verbose";
  char name2[] = "observee";
  //checkAnagrambyLoops(&name1[0],&name2[0]);
  checkAnagrambyArrayTable(&name1[0],&name2[0]);
  return 0;
}
