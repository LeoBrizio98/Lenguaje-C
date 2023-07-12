// Generates pseudorandom numbers in [0,LIMIT), one per line

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Detiene el programa si no se envian los argumentos necesarios en la ejecución del mismo
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Convierte el primer argumento que enviamos luego del comando para iniciar el programa en un int
    int n = atoi(argv[1]);

    // En caso de existir una semilla o seed, indica como trabajar con el número que se introduce como seed
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Imprime en pantalla la lista de números aleatorios generados
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // Success
    return 0;
}
