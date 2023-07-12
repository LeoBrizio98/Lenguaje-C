# include <stdio.h>
# include <cs50.h>
# include <math.h>
# include <stdlib.h>
# include <crypt.h>

int main(void)
{
    int a = 1;
    int b = 1;
    
    int d = 0;
    while (a == b)
    {
        printf ("Hola\n");
        int c = 0;
        while (c < 143)
        {
            int numero = get_int("Dame un numero:");
            if (numero == 5)
            {
                printf ("Hola 5\n");
                numero = 145;
            }
            c = numero;
            a = c;
        }
    }
}