#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}Notebook;

float aplicarDescuento(float precio);

int contarCaracteres(char cadena[], char aContar);

int ordenarXMarcaYPrecio(Notebook lista[], int tam);


int main()
{
    char cadena[20]= "JJJaasdfwet";
    char cuento= 'J';
    int jotas=0;
    float precio=100;
    float descontado= aplicarDescuento(precio);
    printf("Precio: %.2f\nPrecio con descuento: %.2f\n", precio, descontado);
    jotas=contarCaracteres(cadena, cuento);
    printf("Cantidad de %c: %d", cuento, jotas);

    Notebook listado[5]= {{10, "Intel", "Lenovo", 100000}, {11, "AMD", "HP", 150000}, {12, "Intel", "Lenovo", 100850.5}, {13, "AMD", "HP", 100000.8}, {14, "Intel", "Asus", 180000}};
    printf("ID\tPROCESADOR\tMARCA\tPRECIO\n\n");
    printf("LISTA DESORDENADA \n\n");
    for(int i=0; i<5; i++)
    {
        printf("%d\t%s\t       %s\t%.2f\n", listado[i].id, listado[i].procesador, listado[i].marca, listado[i].precio);
    }
    printf("\n\nLISTA ORDENADA POR MARCA (DE LA A A LA Z) Y PRECIO (MENOR A MAYOR)\n\n");
    if(!ordenarXMarcaYPrecio(listado, 5))
    {
        printf("ID\tPROCESADOR\tMARCA\tPRECIO\n\n");
        for(int i=0; i<5; i++)
        {
            printf("%d\t%s\t       %s\t%.2f\n", listado[i].id, listado[i].procesador, listado[i].marca, listado[i].precio);
        }
    }
    return 0;
}

float aplicarDescuento(float precio)
{
    float descontado;

    descontado= precio*0.95;

    return descontado;
}

int contarCaracteres(char cadena[], char aContar)
{
    int i=0, contador=0;
    while(cadena[i] != '\0')
    {
        if(cadena[i]==aContar)
        {
            contador++;
        }
        i++;
    }
    return contador;
}

int ordenarXMarcaYPrecio(Notebook lista[], int tam)
{
    int error=1;
    Notebook auxNotebook;
    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(lista[i].marca, lista[j].marca)>0 || (strcmp(lista[i].marca, lista[j].marca)==0 && lista[i].precio>lista[j].precio))
                {
                    auxNotebook=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxNotebook;
                }
            }
        }
        error=0;
    }
    return error;
}
