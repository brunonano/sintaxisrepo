#include<stdio.h>
#include<stdlib.h>
#include "scanner.h"

int main (int argc, char **argv) 
{
    int token=0; 
    char buffer[500];

    do
    {
        token = get_token (buffer);

        switch (token)
        {
        case 0:
            printf ("Fin de Texto : %s \n", buffer);
            break;
        case 1:
            printf ("Separador : %s \n", buffer);
            break;
        case 2:
            printf ("Cadena : %s \n", buffer);
            break;
        default:
            break;
        }
        
    } while (token != FDT);
}