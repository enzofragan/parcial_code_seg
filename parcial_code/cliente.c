#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

int iniciarClientes(eCliente listaC[],int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        listaC[i].estado=0;
        ret=1;
    }

    return ret;
}

/*int iniciarClientesHardcode(eCliente [])
{
    int id[5] = {100,101,102,103,104};
    char descripcion[5][30] = {"bueno","malo","muy bueno","medio","malo"};
    int importe[5] = {15,30,100,26,40};
    int i;

    for(i=0;i<5;i++)
    {
        listaC[i].idJuedo=id[i];
        strcpy(listaC[i].descripcion,descripcion[i]);
        listaC[i].importe=importe[i];
        listaC[i].estado=1;
    }
}*/

int mostrarClientes(eCliente listaC)
{
    printf("\n%d %s %s %c %s\n",listaC.idCliente,listaC.nombre,listaC.apellido,listaC.sexo,listaC.domicilio);
}

int mostrarListaDeClientes(eCliente listaC[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(listaC[i].estado!=0)
        {
            mostrarClientes(listaC[i]);
        }
    }
}

int menuClientes()
{
    int opcion;

    printf("1- alta cliente\n");
    printf("2- modificacion cliente\n");
    printf("3- baja cliente\n");
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

int buscarLibreClientes(eCliente listaC[],int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if(listaC[i].estado==0)
        {
            ret=i;
            break;
        }
    }

    return ret;
}

int autoIdClientes(eCliente listaC[],int tam)
{
    int i;
    int id;

    i=buscarLibreClientes(listaC,tam);

    id=i+10;

    return id;
}

int repeticionClientes(eCliente listaC[],char nombre[],char apellido[],int tam)
{
    int i;
    int ret=-1;

    for(i=0;i<tam;i++)
    {
        if(strcmp(listaC[i].nombre,nombre)==0 && strcmp(listaC[i].apellido,apellido)==0)
        {
            ret=1;
        }
    }

    return ret;
}

int altaClientes(eCliente listaC[],int tam)
{
    int i;
    int j=0;
    int id;
    int ret=-1;
    int rep;
    char nom[51];
    char apelli[51];
    char sexo;
    char domic[51];


    i=buscarLibreClientes(listaC,tam);

    if(i>=0)
    {
        id=autoIdClientes(listaC,tam);

        getString("ingrese su nombre ","ingrese un nombre valido ",nom);

        getString("ingrese su apellido ","ingrese un apelido valido ",apelli);

        sexo=getChar("ingrese su sexo h(hombre) o m(mujer)","ingrese algo valido ");

        while(sexo!='h' && sexo!='m')
        {
            sexo=getChar("ingrese algo valido ","ingrese algo valido ");
        }

        printf("\ningrese su domicilio xxx-xxx ");
        fflush(stdin);
        gets(domic);

        while(esDomicilio(domic)==-1)
        {
            printf("\ningrese su domicilio xxx-xxx ");
            fflush(stdin);
            gets(domic);
        }

        rep=repeticionClientes(listaC,nom,apelli,tam);


        if(rep<0)
        {
            listaC[i].idCliente=id;
            strcpy(listaC[i].nombre,nom);
            strcpy(listaC[i].apellido,apelli);
            listaC[i].sexo=sexo;
            strcpy(listaC[i].domicilio,domic);
            listaC[i].estado=1;
            ret=0;

            mostrarClientes(listaC[i]);
        }
        else
        {
            printf("\nya ingreso ese cliente \n");
        }


        //system("pause");
    }

    return ret;
}

/*int buscarIdClientes(eCliente [],int )
{
    int i;
    int id;
    int ret=-1;

    printf("ingrese el id del juego ");
    id=getInt("ingrese un id valido ");

    for(i=0;i<tam;i++)
    {
        if(listaC[i].idJuedo==id)
        {
            ret=i;
        }
    }

    return ret;
}

int modificacionClientes(eCliente [],int )
{
    int i;
    int opcion;
    char descrip[51];
    int import;
    int ret=-1;

    i=buscarIdJuego(listaC,tam);

    if(i>=0)
    {
        mostrarJuegos(listaC[i]);

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
            strcpy(listaC[i].descripcion,descrip);
            ret=1;
            break;
        case 2:
            printf("ingrese nuevo importe: ");
            import=getInt("ingrese un importe valido ");
            listaC[i].importe=import;
            ret=1;
            break;
        case 3:
            ret=-1;
            break;
        }

        mostrarJuegos(listaC[i]);
    }
    else
    {
        printf("\nid no encontrado\n\n");
    }

    return ret;
}

int bajaClientes(eCliente [],int )
{
    int i;
    char respuesta;
    int ret=-1;

    i=buscarIdJuego(listaC,tam);

    if(i>=0)
    {
        mostrarJuegos(listaC[i]);

        respuesta=getChar("desea eliminar este juego? s/n ","ingrese una opcion valida ");

        while(respuesta!='s' && respuesta!='n')
        {
            printf("seguro? ");
            fflush(stdin);
            scanf("%c",&respuesta);
        }

        if(respuesta=='s')
        {
            listaC[i].estado=0;
            ret=1;
            mostrarlistaCDeJuegos(listaC,tam);
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
}*/
