#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Comprobar si se inserto un comando valido
    if (argc != 2)
    {
        printf ("Escriba ./caesar <número>\n");
        return 1;
    }

    //Transformar el argumento en entero
    int k = atoi(argv[1]);

    //Pedir el texto sin formato
    string texto = get_string("Plaintext: ");
    int n = strlen(texto);

    //Realizar las iteraciones
    for (int i = 0; i < n; i++)
    {
        int resto = k % 26;
        //Imprimir el código encriptado
        printf ("%c", (((int) texto[i]) + resto));
    }
    printf ("\n");
}