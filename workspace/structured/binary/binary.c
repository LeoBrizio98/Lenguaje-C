#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int midpoint(int x, int y);

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("Use ./binary <valor> <tamaño>");
        return 1;
    }
    
    int n = atoi(argv[2]);
    int tabla[n];

    printf("Escriba %i números ordenados de menor a mayor\n", n);
    for (int i = 0; i < n; i++)
    {
        tabla[i] = get_int("");
    }
    
    int s = atoi(argv[1]);
    
    int min = tabla[0];
    int max = tabla[n-1];
    int buscador = 0;
    bool check;
    
    // Algoritmo de busqueda binaria
    while (min <= max)
    {
        int mid = midpoint(min, max);
        if (s == tabla[mid])
        {
            check = true;
            buscador = mid;
            break;
        }
        
        else if (s < tabla[mid])
        {
            max = (mid - 1);
        }
        
        else if (s > tabla[mid])
        {
            min = (mid + 1);
        }
        
        else
        {
            check = false;
        }
    }
    if (check == true)
    {
        printf("El número esta en el orden %i \n", buscador);
    }
    else
    {
        printf("El número no esta en la matriz \n");
    }
    return check;
}

int midpoint(int x, int y)
{
    return ((x + y) / 2);
}