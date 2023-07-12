# include <stdio.h>
# include <stdlib.h>
# include <cs50.h>
# include <time.h>

int main(void)
{
    int matriz[10];
    for (int i = 0; i < 10; i++)
    {
        matriz[i] = (rand() % 100);
        printf ("%i ", matriz[i]);
    }
    
}