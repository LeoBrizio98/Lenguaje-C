// Helper functions for the sort race

#include <cs50.h>
#include "helpers.h"
#include <stdio.h>
#include <string.h>

// Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    char *comp = str;
    char *a = "-a";
    char *b = "-b";
    char *r = "-r";    
    char *s = "-s";    
    
    if (comp == a || comp == b || comp == r || comp == s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Sorts array of n values using bubble sort
void bubble(int values[], int n)
{
    // Definimos las variables a utilizar
    int tabla[n];
    char aux;
    
    for (int l = 0; l < n; l++)
    {
        tabla[l] = values[l];        
    }
    
    // Incluimos un contador de swaps distinto de 0
    int swaps = 1;
    
    // Un bucle que termine cuando no haya ningun cambio
    while (swaps != 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            swaps = 0; // Lo iniciamos en 0
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

// Sorts array of n values using selection sort
void selection(int values[], int n)
{
    // Definimos los valores que utilizaremos
    int tabla[n];
    char aux;
    
    for (int l = 0; l < n; l++)
    {
        tabla[l] = values[l];        
    }
    
    // Primer bucle para cambiar el i-esimo valor de la tabla
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        
        // Bucle para buscar el menor valor de la tabla
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
}

// Sorts array of n values using insertion sort
void insertion(int values[], int n)
{
    // Definimos los valores que utilizaremos
    char aux;
    int tabla[n];
    
    for (int l = 0; l < n; l++)
    {
        tabla[l] = values[l];        
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
    
    return;
}
