#include<stdio.h>
#include<stdlib.h>
#include "scanner.h"
#include "ctype.h"

int get_token(char buffer[])
{
    char caracter;
    int i=0;
    const int bufferVacio = 0;

//Mientras el texto no llegue a fin de archivo
    while (EOF != (caracter = getchar()))
    {
        if (isspace(caracter)){ //Si encontre un espacio o tabulacion
            if (i != bufferVacio){ //y el buffer de retorno no esta vacio
                buffer[i] = '\0';
                return CAD; 
            }
            continue; //sino lo ignoro y continuo leyendo
        }
        else if (caracter == ',') //Si encontre una coma
            {
                if (i != bufferVacio) //y el buffer de retorno no esta vacio
                {
                    ungetc(caracter, stdin); //devuelvo la coma al stdin
                    buffer[i] = '\0';
                    return CAD;
                }
                buffer[0] = ',';
                buffer[1] = '\0';
                return SEP;     
            }
        else //Si no encuentro espacios en blanco ni comas
        {
            buffer[i] = caracter; //Voy cargando el buffer de salida
            i++;
        }
            
    }

    //Si llegue al final del texto
    if ( i!= bufferVacio) //y el buffer de retorno no esta vacio
    {
        buffer[i] = '\0';
        return CAD;
    }

    buffer[0] = ' ';
    buffer[1] = '\0';
    return FDT;    

}