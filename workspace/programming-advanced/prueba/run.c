#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int sum (int n);

int main(void)
{
    printf ("Dame un número: ");
    int x = get_int("");
    printf ("Su numero es %i \n", sum(x));
}

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n-1);
}