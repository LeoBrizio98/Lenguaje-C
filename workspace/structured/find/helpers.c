// Helper functions

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"

// Mencionamos la funcion punto medio
int midpoint(int x, int y);

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    // Convertimos la tabla a una para trabajar
    int tabla[n];
    
    for (int i = 0; i < n; i++)
    {
        tabla[i] = values[i];
    }
    
    // Definimos las variables
    int min = tabla[0];
    int max = tabla[n-1];
    bool check;
    
    // Algoritmo de busqueda binaria
    while (min <= max)
    {
        // Llamamos a la funcion punto medio
        int mid = midpoint(min, max);
        
        //Aplicamos el algoritmo de busqueda binaria
        if (value == tabla[mid])
        {
            check = true;
            break;
        }
        
        else if (value < tabla[mid])
        {
            max = (mid - 1);
        }
        
        else if (value > tabla[mid])
        {
            min = (mid + 1);
        }
        
        else
        {
            check = false;
        }
    }
    return check;
}

// Sorts array of n values
void sort(int values[], int n)
{
    // Definimos las variables y creamos la tabla
    char aux;
    int tabla[n];
    
    for (int h = 0; h < n; h++)
    {
        tabla[h] = values[n];
    }
    
    // Implementamos un ordenamiento burbuja
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
    return;
}

// Función punto medio
int midpoint(int x, int y)
{
    return ((x + y) / 2);
}