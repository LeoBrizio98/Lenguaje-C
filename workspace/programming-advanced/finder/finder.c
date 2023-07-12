// Recursively searches for a query in a directory.

#define _DEFAULT_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAXLENGTH 50

// Struct to hold the file name and type / Estructura que contiene el nombre y el tipo de un archivo
typedef struct
{
    string name;
    string type;
}
path;

// Struct to hold the directory info / Estructura que contiene la información del directorio
typedef struct
{
    string name;
    int npaths;
    path *paths;
}
directory;

// String to hold the word to seek / Palabra a buscar
string key;

// The function to search for files in a directory and populate the struct / La funcion para buscar archivos en un directorio y llenar la estructura
directory populate(directory dir);

// The function to recursively iterate through directories and handle files / Función recursiva para iterar a traves de directorios y manejar archivos
int seek(directory dir);


int main(int argc, char *argv[])
{

    // TODO: ensure proper number of command line arguments
    // Garantizamos el número de argumentos correcto
    if (argc != 2)
    {
        if (argc == 3)
        {
            return 0;
        }
        
        else
        {
            printf("Use ./finder <file> <directory> este ultimo opcional\n");
            return 1;
        }
    }
    
    key = argv[1]; // Le damos el valor a la variable key
    

    // Create initial directory and set name string / Crear directorio inicial y establecer el name
    directory dir;
    dir.name = "./";

    // TODO: set "dir"s name based on command line arguments entered / Ingresar a dir el string ingresado en la linea de comandos
    string argumento = argv[2];
    
    if (argc > 2)
    {
            dir.name = argumento;
    }

    return seek(dir);
}


directory populate(directory dir)
{
    // Initialize all pointers and values in the given struct / Inicializar todos los punteros y valores en la estructura dada
    dir.npaths = 0; // Inicializa el numero de paths en 0
    dir.paths = NULL; // paths completa el path con valores nulos
    DIR *dirp; //
    struct dirent* entry; //

    dirp = opendir(dir.name); //
    if (dirp == NULL) // Comprueba si el registro es nulo
    {
        printf("Opening directory failed. Check your input filepath!\n"); // Imprime el mensaje en caso de que el archivo no se pueda abrir
        return dir; // Regresa dir
    }

    while ((entry = readdir(dirp)) != NULL) // 
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) //DT_DIR indica si es un documento, compara si el nombre del archivo es . o ..
        {
            // Allocate zeroed-out memory for the construction of the file name / Asignar una memoria nueva para la construcción del nombre del archivo
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 2); // La función calloc asigna espacios de memoria inicializados con 0
            strcat(name, dir.name);
            strcat(name, entry->d_name);
            strcat(name, "/");

            // Reallocate memory to expand the array / Reasignar memoria para expandir la matriz
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types / Agregar un nuevo elemento a la matriz que contenga nombre y tipo
            path newPath = {.name = name, .type = "directory"}; // Crea una estructura de tipo path con el nombre de newPath, a name le coloca el valor de la cadena name y a type le coloca en este caso formato directorio
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory / Incrementar el número de archivos para el directorio
            dir.npaths++;
        }

        // Else if entry is a file, increase file count and populate the struct / Si la entrada es un archivo, incrementa el contador y llena la estructura
        else if (entry->d_type == DT_REG) // DT_REG Indica que es un archivo
        {
            // Allocate zeroed-out memory for the construction of the file name / Asignar memoria nueva para la construcción del nombre del archivo
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 1);
            strcat(name, dir.name); // Concatena las cadenas name y dir.name
            strcat(name, entry->d_name); // Concatena la nueva cadena name con el name del archivo

            // Reallocate memory to expand the array / Reasigna memoria para expandir la matriz
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types / Agrega un nuevo elemento a la matriz que contiene nombres y tipo
            path newPath = {.name = name, .type = "file"};
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory / Incrementa el contador de archivos en el directorio 
            dir.npaths++;
        }
    }

    // Close directory stream using system call closedir and return struct / Cierra el directorio usando la llamada al sistema closedir y devuelva la estructura
    closedir(dirp);
    return dir;
}

// Recursive function to iterate through directories and search files / Funcion recursiva para iterar entre directorios y buscar archivos
int seek(directory dir)
{
    // TODO
    string compare; // Para comparar la palabra que contiene key
    dir = (populate(dir));
    DIR *dirp; //
    struct dirent* entry; //

    dirp = opendir(dir.name); //
    if (dirp == NULL) // Comprueba si el registro es nulo
    {
        printf("Opening directory failed. Check your input filepath!\n"); // Imprime el mensaje en caso de que el archivo no se pueda abrir
        return 6; // Regresa dir
    }
    while ((entry = readdir(dirp)) != NULL) // 
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) //DT_DIR indica si es un documento, compara si el nombre del archivo es . o ..
        {
            dir = populate(dir);
            seek(dir);
        }
        else if (entry->d_type == DT_REG)
        {
            string str = NULL;
            FILE *fptr;
            fptr = fopen ("found.txt", "a+");
            
            while (fgets(str, 50, fptr))
            {
                if(strcmp(str, key) == 0)
                {
                    
                    fprintf (fptr, "%s %c", dir.paths->name, ' ');
                    break;
                }
            }
            fclose(fptr);
        }
    }    
    closedir(dirp);
    return 0;
}
