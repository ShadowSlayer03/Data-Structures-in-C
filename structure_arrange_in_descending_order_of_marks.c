#include<stdio.h>
int main()
{
int n;
typedef struct Student
{
char name[10];
int usn;
int marks[3];
float average;
}STUDENT;

printf("Enter the no of students\n");
scanf("%d",&n);
STUDENT s[n],x;
int i,j;
for(i=0;i<n;i++)
{
printf("name\n");
scanf("%s",s[i].name);
printf("usn\n");
scanf("%d",&s[i].usn);
printf("marks in sub1\n");
scanf("%d",&s[i].marks[0]);
printf("marks in sub2\n");
scanf("%d",&s[i].marks[1]);
printf("marks in sub3\n");
scanf("%d",&s[i].marks[2]);
s[i].average = s[i].marks[0]+s[i].marks[1]+s[i].marks[2]/3.0;
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(s[i].average<s[j].average)
{
x=s[i];
s[i]=s[j];
s[j]=x;
}
}
}
printf("output\n");
for(i=0;i<n;i++)
{
printf("%s\n",s[i].name);
printf("%d\n",s[i].usn);
printf("%.2f\n",s[i].average);
}
return 0;
}

