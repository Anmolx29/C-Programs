#include<stdio.h>
int fun()
{
  static int count = 0;
  count++;
  return count;
}
int fun1()
{
    int x = 0;
    x++;
    return x;
}
  
int main()
{
  printf("%d ", fun());
  printf("%d ", fun());
  printf("\n%d ", fun1());
  printf("%d ", fun1());
  return 0;
}