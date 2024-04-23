
/* Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMA 10

int main(){

char **nombres;
char *buff;        

buff = (char*)malloc(TAMA*sizeof(char));

nombres = (char**)malloc(5*sizeof(char*));

    for (int i = 0; i < 5; i++)
    {

        nombres[i] = (char*)malloc(TAMA * sizeof(char));


            printf("Ingrese nombre %d: \n", i+1);
            gets(buff);

            strcpy(nombres[i], buff);
        
        
    }


            printf("Nombres: \n");

        for (int i = 0; i < 5; i++)
    {
            puts(nombres[i]);
        
        
    }

    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
    free(nombres);
    free(buff);
    
    return 0;
}