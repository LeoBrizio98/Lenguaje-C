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
    
    for (int h = 0; h < n; h++)
    {
        tabla[h] = argv[1][h];
    }
    
    int swaps = 1;
    while (swaps != 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            swaps = 0;
            if (tabla[i] > tabla[i + 1])
            {
                aux = tabla[i];
                tabla[i] = tabla[i + 1];
                tabla[i + 1] = aux;
                swaps++;
            }
        }
    }
}