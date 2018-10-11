#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juegos.h"

int iniciarJuegos(eJuegos lista[],int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        lista[i].estado=0;
        ret=1;
    }

    return ret;
}

int iniciarJuegosHardcode(eJuegos lista[])
{
    int id[5] = {100,101,102,103,104};
    char descripcion[5][30] = {"bueno","malo","muy bueno","medio","malo"};
    int importe[5] = {15,30,100,26,40};
    int i;

    for(i=0;i<5;i++)
    {
        lista[i].idJuedo=id[i];
        strcpy(lista[i].descripcion,descripcion[i]);
        lista[i].importe=importe[i];
        lista[i].estado=1;
    }
}

int mostrarJuegos(eJuegos lista)
{
    printf("\n%d %s %d\n",lista.idJuedo,lista.descripcion,lista.importe);
}

int mostrarListaDeJuegos(eJuegos lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=0)
        {
            mostrarJuegos(lista[i]);
        }
    }
}

int menuJuegos()
{
    int opcion;

    printf("1- alta juego\n");
    printf("2- modificacion juego\n");
    printf("3- baja juego\n");
    printf("4- listar\n");
    printf("5- salir\n");

    opcion=getInt("ingrese una opcion valida ");

    while(opcion>5)
    {
        printf("ingrese una opcion valida ");
        opcion=getInt("ingrese una opcion valida ");
    }

    return opcion;
}

int buscarLibreJuegos(eJuegos lista[],int tam)
{
    int i;
    int ret=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int autoIdJuegos(eJuegos lista[],int tam)
{
    int i;
    int id;

    i=buscarLibreJuegos(lista,tam);

    id=i+100;

    return id;
}

int repeticionJuego(eJuegos lista[],char aux[],int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if(strcmp(lista[i].descripcion,aux)==0)
        {
            ret=1;
        }
    }

    return ret;
}

int altaJuegos(eJuegos lista[],int tam)
{
    int i;
    int id;
    int ret=-1;
    int rep;
    char descrip[51];
    int import;

    i=buscarLibreJuegos(lista,tam);

    if(i>=0)
    {
        id=autoIdJuegos(lista,tam);

        getString("ingrese su descripcion ","ingrese una descripcion valido ",descrip);

        printf("ingrese un importe ");
        import=getInt("ingrese un importe valido ");

        rep=repeticionJuego(lista,descrip,tam);


        if(rep<0)
        {
            lista[i].idJuedo=id;
            strcpy(lista[i].descripcion,descrip);
            lista[i].importe=import;
            lista[i].estado=1;
            ret=0;

            mostrarJuegos(lista[i]);
        }
        else
        {
            printf("\nya ingreso ese juego \n");
        }


        //system("pause");
    }
    else
    {
        printf("no hay mas espacio\n");
    }

    return ret;
}

int buscarIdJuego(eJuegos lista[],int tam)
{
    int i;
    int id;
    int ret=-1;

    printf("ingrese el id del juego ");
    id=getInt("ingrese un id valido ");

    for(i=0;i<tam;i++)
    {
        if(lista[i].idJuedo==id)
        {
            ret=i;
        }
    }

    return ret;
}

int modificacionJuego(eJuegos lista[],int tam)
{
    int i;
    int opcion;
    char descrip[51];
    int import;
    int ret=-1;

    i=buscarIdJuego(lista,tam);

    if(i>=0)
    {
        mostrarJuegos(lista[i]);

        printf("que desea modificar?\n");
        printf("1- descripcion\n");
        printf("2- importe\n");
        printf("3- nada\n");

        opcion=getInt("ingrese una opcion valida ");

        while(opcion>3)
        {
            printf("ingrese una opcion valida: ");
            opcion=getInt("ingrese una opcion valida ");
        }

        switch(opcion)
        {
        case 1:
            getString("ingrese nueva descripcion: ","ingrese una descripcion valido ",descrip);
            strcpy(lista[i].descripcion,descrip);
            ret=1;
            break;
        case 2:
            printf("ingrese nuevo importe: ");
            import=getInt("ingrese un importe valido ");
            lista[i].importe=import;
            ret=1;
            break;
        case 3:
            ret=-1;
            break;
        }

        mostrarJuegos(lista[i]);
    }
    else
    {
        printf("\nid no encontrado\n\n");
    }

    return ret;
}

int bajaJuego(eJuegos lista[],int tam)
{
    int i;
    char respuesta;
    int ret=-1;

    i=buscarIdJuego(lista,tam);

    if(i>=0)
    {
        mostrarJuegos(lista[i]);

        respuesta=getChar("desea eliminar este juego? s/n ","ingrese una opcion valida ");

        while(respuesta!='s' && respuesta!='n')
        {
            respuesta=getChar("ingrese una opcion valida ","ingrese una opcion valida ");
        }

        if(respuesta=='s')
        {
            lista[i].estado=-2;
            ret=1;
            mostrarListaDeJuegos(lista,tam);
        }
        else
        {
            ret=0;
        }

    }
    else
    {
        printf("\nid no encontrado\n\n");
    }

    return ret;
}

int mostrarOrdenJuegos(eJuegos lista[],int tam)
{
    int i;
    int j;
    int ret=-1;
    eJuegos aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].estado==1 && lista[i].estado==1)
            {
                if(strcmp(lista[i].descripcion,lista[j].descripcion)<0)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                    ret=1;
                }
                if(lista[i].importe>lista[j].importe)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }
        }
    }

    mostrarListaDeJuegos(lista,tam);

    return ret;
}
