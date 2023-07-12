#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 8;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j % 2 == 0){
                printf (" r ");
            }
            else{
                printf (" a ");
            }
        }
        printf ("\n");
    }
}