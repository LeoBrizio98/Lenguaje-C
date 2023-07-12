# include <cs50.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char grid[4][4];

void scramble(void);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Use draw <0> or <1>\n");
        return 1;
    }

    char letras[16] = {'T', 'H', 'S', 'G', 'S', 'I', 'N', 'E', 'T', 'D', 'R', 'A', 'R', 'E', 'L', 'T'};
    int n = 4;
    int x = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            grid[i][j] = letras[x];
            x++;
        }
    }

    int prueba = atoi(argv[1]);
    if (prueba == 1)
    {
        scramble();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}


void scramble(void)
{
    char sub[4][4];
    int p = 4;

    for(int x = 0; x < p; x++)
    {
        int b = 3;
        for (int y = 0; y < p; y++)
        {
            sub[x][y] = grid[b][x];
            b--;
        }

    }

    for(int c = 0; c < p; c++)
    {
        for (int d = 0; d < p; d++)
        {
            grid[c][d] = sub[c][d];
        }
    }
}