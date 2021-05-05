#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char *tiposproductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto
{
    int ProductoID;
    int cantidad;
    char *TipoProducto;
    float precioUnitario;
}Productos;


typedef struct Cliente
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosApedir;
    Productos *Productos;

}Cliente;


void nuevoCliente(Cliente *vec_cliente, int cantC);
Productos *cargarProductos(int cantP);
void mostrar(Cliente *Mcliente,int cantC);
float mostrarp(Productos lista);


int main(){
    int cantClientes;
    do{
        printf("\ningrese la cantidad de cientes: ");
        scanf("%d",&cantClientes);
    }while(cantClientes<=0 || cantClientes>6);
    
    Cliente *nuevoC=(Cliente*)malloc(sizeof(Cliente)*cantClientes);
    nuevoCliente(nuevoC,cantClientes);
    mostrar(nuevoC,cantClientes);


printf("\n");
return 0;
}


//Funcion cargar clientes Cliente con los datos

void nuevoCliente(Cliente *vec_cliente,int CantC){
    int cantProductos=rand()%6;
    char *nombre[20];
    int aleatorio=rand()%6;
                        for (int i = 0; i < CantC; i++)
                        {
                            /* code */
                        vec_cliente[i].ClienteID=i+1;    
                        vec_cliente[i].NombreCliente=(char*)malloc(sizeof(char)*10);
                         printf("\n<<<<<<<<<<<<------------------->>>>>>>>>>");
                        printf("\nInggrese el nombre del Cliente: ");
                        fflush(stdin);
                        gets(vec_cliente[i].NombreCliente);
                        
                        //printf("\nnombre %s",vec_cliente[i].NombreCliente);
                        //strcpy(vec_cliente[i].NombreCliente,*nombre);
                        vec_cliente[i].CantidadProductosApedir=cantProductos;
                        vec_cliente[i].Productos=cargarProductos(cantProductos);
                     }
}

//Funcion cargar productos
Productos * cargarProductos(int cantP){
       Productos *vec_nuevoP=(Productos*)malloc(sizeof(Productos)*cantP);
      int aleatorio=rand()%6;
      for (int i = 0; i < cantP; i++)
      {
          /* code */
          vec_nuevoP[i].cantidad=rand()%6;
          vec_nuevoP[i].precioUnitario=(float)(rand() % 91) / 10;
          vec_nuevoP[i].ProductoID=i+1;
          vec_nuevoP[i].TipoProducto=(char*)malloc(sizeof(char)*strlen(tiposproductos[aleatorio]));
          strcpy(vec_nuevoP[i].TipoProducto,tiposproductos[aleatorio]);
      }
      
      
    return vec_nuevoP;
}

//Funcion mostrar
void mostrar(Cliente *Mcliente,int cantC){
    float totalapagar=0;
    for (int i = 0; i < cantC; i++)
    {
        /* code */
     printf("\n///////------------/////////////");
    printf("\nId del Cliente: %d",Mcliente[i].ClienteID);
    printf("\nNombre de cliente= %s",Mcliente[i].NombreCliente);
    printf("\nCantidad de productos pedidos: %d",Mcliente[i].CantidadProductosApedir);
                    for (int j= 0; j < Mcliente[i].CantidadProductosApedir; j++)
                    {
                        totalapagar=totalapagar+mostrarp(Mcliente[i].Productos[j]);
                     
                    }
        printf("\n///////TOTAL A PAGAR : %f",totalapagar);
    }
    
    
        
}

float mostrarp(Productos lista){
     printf("\n<<<<<<<<<<<<<<<>>>>>>>>>>>>>");
    printf("\n Id del producto:%d", lista.ProductoID);
    printf("\n precio unitario:%f",lista.precioUnitario);
    printf("\n Tipoproducto:%s",lista.TipoProducto);
    printf("\n cantidad:%d",lista.cantidad);
    return(lista.cantidad*lista.precioUnitario);
}
