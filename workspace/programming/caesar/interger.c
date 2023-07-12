#include <stdio.h>
#include <cs50.h>

int main(void)
{ 
    int x = get_int("Dame un número: ");
    x = x % 26;
    printf ("%i\n", x);
}