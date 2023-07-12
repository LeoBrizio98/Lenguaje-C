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
    
    for (int i = 1; i < n; i++)
    {
        aux = tabla[i];
        int j = i;
        
        while (j > 0 && tabla[j - 1] > aux)
        {
            tabla[j] = tabla [j - 1];
            j = j - 1;
        }
        tabla[j] = aux;
    }
    
    printf ("Su tabla ordenada es: ");
    
    for (int k = 0; k < n; k++)
    {
        printf ("%c ", tabla[k]);
    }
    printf ("\n)");
}