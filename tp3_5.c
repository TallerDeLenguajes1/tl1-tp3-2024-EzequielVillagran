
/* Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMA 10

int main(){

char **nombres;
char *buff;        
int cant = 0;

buff = (char*)malloc(TAMA*sizeof(char));


printf("Ingrese la cantidad de nombres a almacenar: \n");
scanf("%d", &cant);
nombres = (char**)malloc(sizeof(char*)*cant);

    for (int i = 0; i < cant; i++)
    {



            printf("Ingrese nombre %d: \n", i+1);
            gets(buff);
            fflush(stdin);
           nombres[i] = (char*)malloc((strlen(buff)+1)* sizeof(char));
            strcpy(nombres[i], buff);
        
        
    }


            printf("Nombres: \n");

        for (int i = 0; i < cant; i++)
    {
            puts(nombres[i]);
        
        
    }

    for (int i = 0; i < cant; i++)
    {
        free(nombres[i]);
    }
    free(nombres);
    free(buff);
    
    return 0;
}