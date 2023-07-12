# include <cs50.h>
# include <stdio.h>
# include <string.h>
#include <ctype.h>

int main (void)
{
	//Analisis del primer nombre de la cadena
	string s = get_string("");
	int n = strlen(s);
	printf("%c", toupper(s[0]));

	//Analisis de los demas nombres de la cadena
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' ')
		printf("%c", toupper(s[i+1]));
	}
	
	printf ("\n");
}
