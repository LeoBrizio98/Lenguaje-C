# include <stdio.h>
# include <cs50.h>
# include <math.h>
# include <stdlib.h>
# include <crypt.h>

int main(int argc, string argv[])
{
    //Comprobar que el programa reciba los datos correctos
    if (argc != 2)
    {
        printf ("Escriba ./crack <código>\n");
        //Detener en caso de que no sea correcto
        return 1;
    }
    //Definimos algunas variables
    string contraseña = "Hola";
    string clave = (argv[1]);
    
    for (int i = 0; i < 5; i++)
    {
        char matriz[i];
        if (i == 0) // Para 1 solo dígito
        {
            int cifra = 65; //Comenzamos el bucle con A
            while (cifra < 123)
            {
                if (cifra == 91)
                {
                    cifra = cifra + 6;
                }
                
                matriz[i] = (char) cifra;
                string crack = crypt (matriz,"50"); //El hash y el salt
                
                if (crack == clave)
                {
                    contraseña = matriz;
                    cifra = 250;
                    i = 10;
                }
                
                cifra++;
            }
        }
        
        else if (i == 1) // Para 2 dígitos
        {
            int cifra1 = 65; //Comenzamos el bucle con A
            
            while (cifra1 < 123)
            {
                if (cifra1 == 91)
                {
                    cifra1 = cifra1 + 6;
                }
                //Definir la matriz
                matriz[0] = (char) cifra1;
                
                int cifra2 = 65; //Comenzamos el bucle con A
                
                while (cifra2 < 123)
                {
                    if (cifra2 == 91)
                    {
                        cifra2 = cifra2 + 6;
                    }
                    matriz[i] = (char) cifra2;
                    string crack = crypt (matriz,"50"); //El hash y el salt
                
                    if (crack == clave)
                    {
                        contraseña = matriz;
                        cifra1 = 250;
                        cifra2 = 250;
                        i = 10;
                    }
                    cifra2++;
                }
                cifra1++;
            }
        }
        
        else if (i == 2) // Para 3 dígitos
        {
            int cifra31 = 65; //Comenzamos el bucle con A
            
            while (cifra31 < 123)
            {
                if (cifra31 == 91)
                {
                    cifra31 = cifra31 + 6;
                }
                //Definir la matriz en [0]
                matriz[0] = (char) cifra31;
                
                int cifra32 = 65; //Comenzamos el bucle con A
                
                while (cifra32 < 123)
                {
                    if (cifra32 == 91)
                    {
                        cifra32 = cifra32 + 6;
                    }
                    matriz[1] = (char) cifra32; //Mi matriz en [1]
                    
                    int cifra33 = 65; //Comenzamos el bucle con A
                    
                    while (cifra33 < 123)
                    {
                        if (cifra33 == 91)
                        {
                            cifra33 = cifra33 + 6;
                        }
                        matriz[i] = (char) cifra33;
                    
                        string crack = crypt (matriz,"50"); //El hash y el salt
                
                        if (crack == clave)
                        {
                            contraseña = matriz;
                            cifra33 = 250;
                            cifra32 = 250;
                            cifra31 = 250;
                            i = 10;
                        }
                        cifra33++;
                    }
                    cifra32++;
                }
                cifra31++;
            }
        }
        
        else if (i == 3) // Para 4 dígitos
        {
            int cifra41 = 65; //Comenzamos el bucle con A
            
            while (cifra41 < 123)
            {
                if (cifra41 == 91)
                {
                    cifra41 = cifra41 + 6;
                }
                //Definir la matriz en [0]
                matriz[0] = (char) cifra41;
                
                int cifra42 = 65; //Comenzamos el bucle con A
                
                while (cifra42 < 123)
                {
                    if (cifra42 == 91)
                    {
                        cifra42 = cifra42 + 6;
                    }
                    matriz[1] = (char) cifra42;
                    
                    int cifra43 = 65; //Comenzamos el bucle con A
                    
                    while (cifra43 < 123)
                    {
                        if (cifra43 == 91)
                        {
                            cifra43 = cifra43 + 6;
                        }
                        matriz[2] = (char) cifra43;
                        
                        int cifra44 = 65; //Comenzamos el bucle con A
                        
                        while (cifra44 < 123)
                        {                 
                            if (cifra44 == 91)
                            {
                                cifra44 = cifra44 + 6;
                            }
                            matriz[i] = (char) cifra44;
                            
                            string crack = crypt (matriz,"50"); //El hash y el salt
                
                            if (crack == clave)
                            {
                                contraseña = matriz;
                                cifra44 = 250;
                                cifra43 = 250;
                                cifra42 = 250;
                                cifra41 = 250;
                                i = 10;
                            }
                            cifra44++;
                        }
                        cifra43++;
                    }
                    cifra42++;
                }
                cifra41++;
            }
        }
        
        else if (i == 4) // Para 5 dígitos
        {
            int cifra51 = 65; //Comenzamos el bucle con A
            
            while (cifra51 < 123)
            {
                if (cifra51 == 91)
                {
                    cifra51 = cifra51 + 6;
                }
                //Definir la matriz en [0]
                matriz[0] = (char) cifra51;
                
                int cifra52 = 65; //Comenzamos el bucle con A
                
                while (cifra52 < 123)
                {
                    if (cifra52 == 91)
                    {
                        cifra52 = cifra52 + 6;
                    }
                    matriz[1] = (char) cifra52;
                    
                    int cifra53 = 65; //Comenzamos el bucle con A
                    
                    while (cifra53 < 123)
                    {
                        if (cifra53 == 91)
                        {
                            cifra53 = cifra53 + 6;
                        }
                        matriz[2] = (char) cifra53;
                        
                        int cifra54 = 65; //Comenzamos el bucle con A
                        
                        while (cifra54 < 123)
                        {                 
                            if (cifra54 == 91)
                            {
                                cifra54 = cifra54 + 6;
                            }
                            matriz[3] = (char) cifra54;
                            
                            int cifra55 = 65;
                            
                            while (cifra55 < 123)
                            {
                                if (cifra55 == 91)
                                {
                                    cifra55 = cifra55 + 6;
                                }
                                matriz[i] = (char) cifra55;
                                
                                string crack = crypt (matriz,"50"); //El hash y el salt
                
                                if (crack == clave)
                                {
                                    contraseña = matriz;
                                    cifra55 = 250;
                                    cifra54 = 250;
                                    cifra53 = 250;
                                    cifra52 = 250;
                                    cifra51 = 250;
                                    i = 10;
                                }
                                cifra55++;
                            }
                            cifra54++;
                        }
                        cifra53++;
                    }
                    cifra52++;
                }
                cifra51++;
            }
        }
    }
    printf ("%s\n", contraseña);
}