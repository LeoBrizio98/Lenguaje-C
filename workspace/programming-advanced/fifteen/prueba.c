# include <stdio.h>
# include <stdlib.h>
# include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: prueba d\n");
        return 1;
    }
    int z = atoi(argv[1]);
    int blocks = (z * z);
    int rest = z % 2;
    char tablero[blocks];

    if (rest == 0)
    {
        int casilla = (blocks - 1);

        for (int a = 0; a < blocks; a++)
        {
            if (a == (blocks - 3))
            {
                casilla = 1;
            }
            else if (a == (blocks - 2))
            {
                casilla = 2;
            }
            else if (a == (blocks - 1))
            {
                casilla = '_';
            }
            tablero[a] = casilla;
            printf ("%i ", tablero[a]);
            casilla--;
        }
    }

    else if (rest == 1)
    {
        int casilla = (blocks - 1);

        for (int a = 0; a < blocks; a++)
        {
            if (a == (blocks - 1))
            {
                casilla = '_';
            }
            tablero[a] = casilla;
            printf ("%i ", tablero[a]);
            casilla--;
        }
    }
    printf ("\n");
}