// Converts degrees C to degrees F by collecting info at command line

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Obtener celsius desde el inicio del programa
    

    //Condicionar al programa a solo obtener 1 dato
    if (argc != 2)
    {
        printf("Utilizar ./fahrenheit <grados>\n");
        return 1;
    }
    // Convert to fahrenheit; no float errors b/c celsius is a float
    else
    {
        float celsius = atof(argv[1]);
        float fahrenheit = (celsius * 9) / 5 + 32;
        printf("F: %.1f\n", fahrenheit);
    }
}
