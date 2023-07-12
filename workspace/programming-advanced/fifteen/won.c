# include <cs50.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, string argv[])
{
    int dim = atoi(argv[1]);
    int casillas = dim * dim;
    char tablero[casillas];
    
    for (int i = 0; i < casillas - 2; i++)
    {
        if (tablero[i] < tablero[i + 1])
        {
            return true;
            break;
        }
        else
        {
            return false;
        }
    }
}