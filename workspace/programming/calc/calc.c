# include <stdio.h>
# include <cs50.h>
# include <math.h>
# include <stdlib.h>

int main(int argc, string argv[])
{
    

    //Reconocer los valores que se ingresan
    if (argc != 4) //Esto revisa que se ingresan 2 números positivos y un operador
    {
        printf("Escriba ./calc <número> <operador> <número>\n");
        return 1; // Devuelve error en caso de no ingresar lo que necesitamos
    }
    
    //Pasar los valores a flotantes
    float x = atof(argv[1]);
    float y = atof(argv[3]);
    float total = 0;
    //Identificar el operador matemático
    char c = argv[2][0];

    //Realizar la operación correspondiente
    if ((int) c == 43) //Suma
    {
        total = (x + y);
        printf ("%.6f\n", total);
    }

    else if ((int) c == 45) //Resta
    {
        total = (x - y);
        printf ("%.6f\n", total);
    }

    else if ((int) c == 120) //Multiplicación
    {
        total = (x * y);
        printf ("%.6f\n", total);
    }

    else if ((int) c == 47) //División
    {
        total = (x / y);
        printf ("%.6f\n", total);
    }

    else if ((int) c == 37) //Resto
    {
        int q = x / y;
        total = (x - (q * y));
        printf ("%.6f\n", total);
    }
}