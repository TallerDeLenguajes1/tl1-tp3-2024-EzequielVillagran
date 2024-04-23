#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 12

int main(){

srand(time(NULL));

int empresa[N][M];
int suma;
float prom;
int max = 0;
int maxj = 0;
int maxAnio;
int maxMes;

for (int i = 0; i < N; i++)
{
    printf("Anio: %d\n", i+1);
    for (int j = 0; j < M; j++)
    {
        empresa[i][j] = 10000 + rand()%40001;
        printf("Cosecha mes %d: %d \n", j+1, empresa[i][j]);

    }


}

for (int i = 0; i < N; i++)
{
    
    for (int j = 0; j < M; j++)
    {
        suma = suma + empresa[i][j];

    }

   prom = suma/3; 

   printf("Promedio del anio %d: %.2f\n",i+1, prom);

}

for (int i = 0; i < N; i++)
{
    
    for (int j = 0; j < M; j++)
    {
       if (empresa[i][j]>max)
       {
        max = empresa[i][j];
        maxAnio = i+1;
        maxMes = j+1;
       }
       
       

    }
    
    

}

printf("La cosecha maxima corresponde a la fecha %d/%d y fue de %d", maxAnio, maxMes, max);

    return 0;
}