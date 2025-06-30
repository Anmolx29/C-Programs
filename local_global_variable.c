#include <stdio.h>
#include <conio.h>
int x = 15;                  //global variable
void main()
{
    int x = 20;              //local variable 
    printf("%d", x);
    getch();
}