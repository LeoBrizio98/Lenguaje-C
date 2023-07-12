# include <cs50.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, string argv[])
{
    int tile = get_int("Tecla a mover: ");
    int buscador = 0;
    int dim = atoi(argv[1]);
    int casillas = dim * dim;
    char tablero[casillas];
    int fichas = casillas - 1;
    tablero[fichas] = '_';
    int x = fichas;
    
    for (int i = 0; i < fichas; i++)
    {
        tablero[i] = x;
        x--;
    }
    for (int e = 0; e < casillas; e++)
    {
        if (tablero[e] == tile)
        {
            buscador = e;
            break;   
        }    
    }
    
    string respuesta;
    
    if ((int) tablero[buscador + 1] == 95)
    {
        respuesta = "Verdadero";
    }
    
    else if ((int) tablero[buscador - 1] == 95)
    {
        respuesta = "Verdadero";
    }
    
    else if ((int) tablero[buscador + dim] == 95)
    {
        respuesta = "Verdadero";
    }
    
    else if ((int) tablero[buscador - dim] == 95)
    {
        respuesta = "Verdadero";
    }
    
    else
    {
        respuesta = "Falso";
    }
    
    printf ("El resultado es %s\n", respuesta);
}