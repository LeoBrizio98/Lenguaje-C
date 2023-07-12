# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int n = 0;
    int i;
    int array[n];
    int min;
    for (i = 1; i < (n - 1); i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        
        if (min != 1)
        {
            int x;
            x = array[i];
            array[i] = array[min];
            array[min] = x;
        }
    }
}