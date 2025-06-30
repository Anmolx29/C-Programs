#include <stdio.h>

void hanoi_tower (char, char, char, int); 

void hanoi_tower (char BEG, char AUX, char END, int n)
{
    if (n<=0)

    printf ("\n illegal entry");

    if (n == 1)

    printf ("\n Move Disk from %c to %c", BEG, END);

    else

{
    hanoi_tower (BEG, END, AUX, n-1);

    hanoi_tower (BEG, AUX, END, 1);

    hanoi_tower (AUX, BEG, END, n-1);

}
}

void main() 
{
int n; 

char x, y, z;  

printf ("\n Enter the number of disc: ");

scanf ("%d", & n); 

printf ("\n Tower of Hanoi for %d Disc", n);

hanoi_tower ('x', 'y', 'z', n);

}