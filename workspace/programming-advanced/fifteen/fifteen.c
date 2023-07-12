// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
char *init(int dim, char *tablero);
void draw(int large, char *tablero);
bool move(int tile, int dim, char *tablero);
bool won(int dim, char *tablero);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);


int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    char tablero[d];
    init(d, tablero);
    
    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw(d, tablero);

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won(d, tablero))
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        printf("Tile to move: ");
        int tile;
        tile = get_int("");

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile, d, tablero))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
char *init(int dim, char *tablero)
{
    //Definimos las variables que vamos a necesitar
    int casillas = dim * dim;
    int fichas = casillas - 1;
    int rest = dim % 2;
    tablero[fichas] = '_';

    //Comprobamos si la matriz es par
    if (rest == 0)
    {
        int pos = (casillas - 1);
        
        //Creamos la matriz de juego
        for (int a = 0; a < casillas - 1; a++)
        {
            if (a == (casillas - 3)) //Cambiamos las ultimas 2 fichas, la 2 remplazando a la 1
            {
                pos = 1;
            }
            else if (a == (casillas - 2))
            {
                pos = 2;
            }
            
            tablero[a] = pos;
            pos--;
        }
    }
    
    //Comprobamos si la matriz es impar
    else if (rest == 1)
    {
        int casilla = casillas;
        
        //Creamos la matriz de juego
        for (int a = 0; a < casillas - 1; a++)
        {
            tablero[a] = casilla;
            casilla--;
        }
    }
    return tablero;
}

// Prints the board in its current state
void draw(int large, char tablero[])
{
    // Le indicamos al programa como imprimir el tablero en todo momento
    int x = 0;
    for (int i = 0; i < large; i++)
    {
        for (int p = 0; p < large; p++)
        {
            if (tablero[x] == 95) // Aqui imprimimos unicamente '_'
            {
                printf ("%c   ",tablero[x]);
                x++;
            }
                
            else if (tablero[x] < 10) // Si el número es de una sola cifra, le agregamos un espacio
            {
                printf ("%i   ",tablero[x]);
                x++;
            }
            else
            {
                printf ("%i  ",tablero[x]);
                x++;
            }
        }
        printf ("\n");
        printf ("\n"); //Doble salto de linea para obtener un tablero mas estético
    }
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile, int dim, char *tablero)
{
    // Definimos las variables a utilizar
    int casillas = dim * dim;
    int buscador = 0;
    int aux = 0;
    
    // Aqui verificamos que número es tile
    for (int e = 0; e < casillas; e++)
    {
        if (tablero[e] == tile)
        {
            buscador = e;
            break;   
        }    
    }
    
    // Luego verificamos si tile es una ficha que se puede mover o no
    if ((int) tablero[buscador + 1] == 95) // Si se puede mover, que se mueva un lugar a la derecha
    {
        aux = tablero[buscador + 1];
        tablero[buscador + 1] = tile;
        tablero[buscador] = aux;
        return true;
    }
    
    else if ((int) tablero[buscador - 1] == 95) // Si se puede mover, que se mueva un lugar a la izquierda
    {
        aux = tablero[buscador - 1];
        tablero[buscador - 1] = tile;
        tablero[buscador] = aux;
        return true;
    }
    
    else if ((int) tablero[buscador + dim] == 95) // Si se puede mover, que se mueva un lugar hacia abajo
    {
        aux = tablero[buscador + dim];
        tablero[buscador + dim] = tile;
        tablero[buscador] = aux;
        return true;
    }
    
    else if ((int) tablero[buscador - dim] == 95) // Si se puede mover, que se mueva un lugar hacia arriba
    {
        aux = tablero[buscador - dim];
        tablero[buscador - dim] = tile;
        tablero[buscador] = aux;
        return true;
    }
    
    else
    {
        return false;
    }
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(int dim, char *tablero)
{
    int casillas = dim * dim; // Para definir la cantidad de fichas del tablero
    // Función que define si ganaste
    for (int i = 0; i < casillas - 2; i++) // Llega hasta la antepenultima ficha evitando comparar con '_'
    {
        bool final = false;
        if (tablero[i] > tablero[i + 1])
        {
            final = false; // En caso de que esten las fichas acomodadas, devuelve verdadero
            break;
        }
        else
        {
            final = true; // En caso de que no esten las fichas acomodadas, devuelve falso
            break; 
        }    
    return final;
    }

    return 0;
}
