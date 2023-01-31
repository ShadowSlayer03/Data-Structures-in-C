//Tower Of Hanoi prob
// We have rings in descending order of size. No of rings will be specified. We also have 3 rods A,B,C
// We need to Move all rings from rod A to C
// But only each ring can be moved at a time
// And smaller rings cannot be kept on top of larger rings
// No of steps req = (2^n)-1
#include<stdio.h>
void TOH(int n,int A,int B,int C)
{
  if(n>0)
  {
    TOH(n-1,A,C,B);
    printf("Move from %d to %d\n",A,C);
    TOH(n-1,B,A,C);
  }
}
int main()
{
  TOH(5,1,2,3);
  return 0;
}