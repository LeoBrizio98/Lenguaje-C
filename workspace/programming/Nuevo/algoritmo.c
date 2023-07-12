#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int gallinas;
    int dias;
    dias = 30;
    gallinas = 5;
    int huevos[gallinas];
    for (int j = 0; j < dias; j++)
    {
        for (int i = 0; i < gallinas; i++)
        {
            printf("Ingrese los huevos de la gallina %i \n", i);
            int aux = get_int("");
            huevos[i] = huevos[i] + aux;
        }
    }