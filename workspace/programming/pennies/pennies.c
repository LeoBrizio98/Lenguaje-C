#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    //Recopilación de datos
    int n = 0;
    
    //Bucle de dia del mes
    //Devolver si el valor no esta entre 28 y 31
    do
    {
        n = get_int("Dias del mes: ");
    }

    while (32 <= n || n <= 27);

    int c;
    
    //Pedir la cantidad de centavos
    //Devolver si los centavos no son mayores a 0
    do
    {
        c = get_float("Centavos el primer dia: ");
    }

    while (c <= 0);
    
    long long total = c;

    //Cálculo de valor final
    for ( int a = 0; a < n; a++)
    {
    total += c * pow(2,a);
    }
    
    //Pasar a formato Double el long long obtenido
    double t = ((double) total) / 100;
    printf ("$: %.2f\n", t);
}