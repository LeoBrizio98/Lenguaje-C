# include <stdio.h>
# include <stdlib.h>
# include <cs50.h>

int main(int argc, string argv[])
{
    int t = atoi (argv[1]);
    int c = t * t;
    char tablero[c];
    int fichas = (c - 1);
    int y = fichas;
    int x = 0;
    tablero[y] = '_';
    
    for (int a = 0; a < fichas; a++)
    {
        tablero[a] = y;
        y--;
    }
    for (int i = 0; i < t; i++)
    {
        for (int p = 0; p < t; p++)
        {
            if (tablero[x] < 10)
            {
                printf ("%i   ",tablero[x]);
                x++;
            }
            else if ((int)tablero[x] == 95)
            {
                printf ("%c   ",tablero[x]);
                x++;
            }
            else
            {
                printf ("%i  ",tablero[x]);
                x++;
            }
        }
        printf ("\n");
        printf ("\n");
    }
}