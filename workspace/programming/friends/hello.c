// Greets a user by their name

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //Comprueba la cadena y luego imprime error.
    if (argc != 2)
    {
        printf("Utilice ./hello <name>\n");
        return 1;
    }
    //Comprobada la cadena como cierta, imprime Hello, name.
    else 
    {
        printf("Hello, %s\n", argv[1]);
    }
}