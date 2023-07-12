#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{    
    if (argc != 2)
    {
        printf ("Escriba ./selection <matriz de valores>\n");
        return 1;
    }
    int n = strlen(argv[1]);
    char aux;
    int tabla[n];
    printf ("%i\n", n);
    
    for (int h = 0; h < n; h++)
    {
        tabla[h] = argv[1][h];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (tabla[j] < tabla[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            aux = tabla[i];
            tabla[i] = tabla[min];
            tabla[min] = aux;
        }
        
    }
    printf ("Su tabla ordenada es: ");
    for (int k = 0; k < n; k++)
    {
        printf ("%c ", tabla[k]);
    }
    printf ("\n");
}