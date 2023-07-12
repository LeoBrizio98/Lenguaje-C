# include <stdio.h>
# include <cs50.h>
# include <math.h>
# include <stdlib.h>
# include <crypt.h>

int main (void)
{
    string clave = get_string("Ingrese una clave: ");
    string hash = crypt (clave,"50");
    printf ("Este es el hash: %s\n", hash);
}