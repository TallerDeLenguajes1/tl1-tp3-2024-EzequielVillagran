#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMA 50

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto {
    int ProductoID;             // Numerado en ciclo iterativo
    int Cantidad;               // entre 1 y 10
    char *TipoProducto;         // Algún valor del arreglo TiposProductos
    float PrecioUnitario;       // entre 10 - 100
};

typedef struct Producto Producto;

struct Cliente {
    char *NombreCliente;        // Ingresado por usuario
    int ClienteID;              // Numerado en el ciclo iterativo
    int CantidadProductosAPedir;// (aleatorio entre 1 y 5)
    Producto *Productos;        // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
};

typedef struct Cliente Cliente;

void cargarClientes(Cliente *nuevo, int cant);
void mostrarClientes(Cliente *nuevo, int cant);
void liberarClientes(Cliente *nuevo, int cant);
float calcularCosto(Producto producto);
int main() {
    srand(time(NULL));

    Cliente *nuevos;
    int cant = 0;


do
{
    printf("Ingrese cantidad de clientes: ");
    scanf("%d", &cant);
    fflush(stdin);

    
    if (cant > 5) {
        printf("Ingrese cantidad de clientes menor o igual a 5 ");
            }
} while (cant > 5);

    nuevos = malloc(sizeof(Cliente) * cant);

    cargarClientes(nuevos, cant);
    mostrarClientes(nuevos, cant);
    liberarClientes(nuevos, cant);

    return 0;
}


float calcularCosto(Producto producto){

    return producto.Cantidad * producto.PrecioUnitario;


}
void cargarClientes(Cliente *nuevo, int cant) {
    // Guardar el valor inicial del puntero

    char buff[TAMA];


    for (int i = 0; i < cant; i++) {
        
        nuevo[i].ClienteID = 1 + i;

        printf("Ingrese nombre del cliente: ");
        scanf("%s", buff);
        
        nuevo[i].NombreCliente = (char*)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nuevo[i].NombreCliente, buff);

        nuevo[i].CantidadProductosAPedir = 1 + rand() % 5;

        // Asignar memoria para el array de productos
        nuevo[i].Productos = (Producto*)malloc(nuevo[i].CantidadProductosAPedir * sizeof(Producto));
        
        for (int j = 0; j < nuevo[i].CantidadProductosAPedir; j++) {
            
            nuevo[i].Productos[j].ProductoID = j + 1;
            
            nuevo[i].Productos[j].Cantidad = 1 + rand() % 10;
            nuevo[i].Productos[j].PrecioUnitario = ((float)(10 + rand() % 10100))/100;
            
            int tipoIndex = rand() % 5;
            nuevo[i].Productos[j].TipoProducto = (char*)malloc((strlen(TiposProductos[tipoIndex]) + 1) * sizeof(char));
            
            strcpy(nuevo[i].Productos[j].TipoProducto, TiposProductos[tipoIndex]);
        }

      }
}
  
void mostrarClientes(Cliente *nuevo, int cant) {

    float total = 0;
    float costoProducto = 0;


    for (int i = 0; i < cant; i++) {
        printf("Cliente ID: %d\n", nuevo[i].ClienteID);
        printf("Nombre: %s\n", nuevo[i].NombreCliente);
        printf("Cantidad: %d\n", nuevo[i].CantidadProductosAPedir);
        printf("**********************/PRODUCTOS/*****************************\n");

        for (int j = 0; j < nuevo[i].CantidadProductosAPedir; j++) {
            printf("Producto ID: %d\n", nuevo[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", nuevo[i].Productos[j].Cantidad);
            printf("Tipo: %s\n", nuevo[i].Productos[j].TipoProducto);
            printf("Precio: %.2f\n", nuevo[i].Productos[j].PrecioUnitario);
            costoProducto = calcularCosto(nuevo[i].Productos[j]);

            printf("El total por este producto es: %.2f\n", costoProducto);
            total += costoProducto;
        }

        printf("***************************************************\n");
        printf("El total por todos los productos es: %.2f\n", total);
    }
}


void liberarClientes(Cliente *nuevo, int cant) {
    for (int i = 0; i < cant; i++) {
        for (int j = 0; j < nuevo->CantidadProductosAPedir; j++) {
            free(nuevo->Productos[j].TipoProducto);
        }
        free(nuevo->Productos);

        free(nuevo->NombreCliente);
        nuevo++;
    }
}

