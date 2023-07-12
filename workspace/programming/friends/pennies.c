// Calculates how many pennies a user would get if their change doubles each day using command line information

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Defined constants
#define MAX_DAYS 31
#define MIN_DAYS 28

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("Utilizar ./pennies <dias del mes> <centavos por dia>\n");
        return 1;
    }
    //Convertir la cadena de argv en un entero
    int days = atoi(argv[1]);
    
    //Bucle para comprobar que los días del mes sean entre 28 y 31
    while(days < MIN_DAYS || days > MAX_DAYS)
    {
        printf("Escriba un número entre 28 y 31\n");
        return 1;
    }
    
    // Get a number of pennies in [0, inf)
    int pennies = atoi(argv[2]);
    
    // Obtener las iteraciones de dias
    while(pennies <= 0)
    {
        printf("Escriba un número mayor a 0\n");
        return 1;
    }

    // Relatively few pennies required to get out of bounds of int
    long long total = pennies;

    // Add double the amount of pennies of the previous day each day
    for(int i = 1; i < days; i++)
    {
        total += pennies * pow(2,i);
    }

    // Output the total as dollars and cents only
    printf("$%.2f\n", ((double) total) / 100);
}