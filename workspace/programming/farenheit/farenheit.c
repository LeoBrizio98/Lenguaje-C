#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float c = get_float("C: ");
    float f = ((c * 9)/ 5) + 32;
    printf ("F: %.1f\n", f);
}
