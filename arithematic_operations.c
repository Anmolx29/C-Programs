#include <stdio.h>
#include <conio.h>
void main()
{
    int a, b;
    printf("Enter two numbers a and b: \n");
    scanf("%d   %d", &a, &b);
    int sum = a + b ;
    int diff = a - b;
    int mul = a * b;
    float div = a / b;
    int mod = a % b;
    printf("The sum of a and b is: %d\n", sum);
    printf("The differnce of a and b is: %d\n", diff);
    printf("The product of a and b is: %d\n", mul);
    printf("The division of a and b is: %d\n", div);
    printf("The modulus of a and b is: %d\n", mod);
    getch();
}