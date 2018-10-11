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

int iniciarClientesHardcode(eCliente listaC[])
{
    int id[5] = {10,11,12,13,14};
    char nombre[5][51] = {"enzo","luis","ana","lisa","robert"};
    char apellido[5][51] = {"fragan","mario","santos","fragan","percio"};
    char sexo[] = {'h','h','m','m','h'};
    char domicilio[5][51] = {"111-222","222-333","333-444","444-555","555-666"};
    int i;

    for(i=0;i<5;i++)
    {
        listaC[i].idCliente=id[i];
        strcpy(listaC[i].nombre,nombre[i]);
        strcpy(listaC[i].apellido,apellido[i]);
        listaC[i].sexo=sexo[i];
        strcpy(listaC[i].domicilio,domicilio[i]);
        listaC[i].estado=1;
    }
}

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
    else
    {
        printf("no hay mas espacio\n");
    }

    return ret;
}

int buscarIdClientes(eCliente listaC[],int tam)
{
    int i;
    int id;
    int ret=-1;

    printf("ingrese su id del cliente ");
    id=getInt("ingrese un id valido ");

    for(i=0;i<tam;i++)
    {
        if(listaC[i].idCliente==id)
        {
            ret=i;
        }
    }

    return ret;
}

int modificacionClientes(eCliente listaC[],int tam)
{
    int i;
    int opcion;
    char nombre[51];
    char apellido[51];
    char sexo;
    char domicilio[51];
    int ret=-1;

    i=buscarIdClientes(listaC,tam);

    if(i>=0)
    {
        mostrarClientes(listaC[i]);

        printf("que desea modificar?\n");
        printf("1- nombre\n");
        printf("2- apellido\n");
        printf("3- sexo\n");
        printf("4- domicilio\n");
        printf("5- nada\n");

        opcion=getInt("ingrese una opcion valida ");

        while(opcion>5)
        {
            printf("ingrese una opcion valida: ");
            opcion=getInt("ingrese una opcion valida ");
        }

        switch(opcion)
        {
        case 1:
            getString("ingrese nuevo nombre: ","ingrese un nombre valido ",nombre);
            strcpy(listaC[i].nombre,nombre);
            ret=1;
            break;
        case 2:
            getString("ingrese nuevo apellido: ","ingrese un apellido valido ",apellido);
            strcpy(listaC[i].apellido,apellido);
            ret=1;
            break;
        case 3:
            sexo=getChar("ingrese su sexo h(hombre) o m(mujer)","ingrese algo valido ");
            while(sexo!='h' && sexo!='m')
            {
                sexo=getChar("ingrese algo valido ","ingrese algo valido ");
            }
            listaC[i].sexo=sexo;
            ret=1;
            break;
        case 4:
            printf("\ningrese su nuevo domicilio xxx-xxx ");
            fflush(stdin);
            gets(domicilio);

            while(esDomicilio(domicilio)==-1)
            {
                printf("\ningrese su domicilio xxx-xxx ");
                fflush(stdin);
                gets(domicilio);
            }
            strcpy(listaC[i].domicilio,domicilio);
            ret=1;
            break;
        case 5:
            ret=-1;
            break;
        }

        mostrarClientes(listaC[i]);
    }
    else
    {
        printf("\nid no encontrado\n\n");
    }

    return ret;
}

int bajaClientes(eCliente listaC[],int tam)
{
    int i;
    char respuesta;
    int ret=-1;

    i=buscarIdClientes(listaC,tam);

    if(i>=0)
    {
        mostrarClientes(listaC[i]);

        respuesta=getChar("desea eliminar este juego? s/n ","ingrese una opcion valida ");

        while(respuesta!='s' && respuesta!='n')
        {
            respuesta=getChar("desea eliminar este juego? s/n ","ingrese una opcion valida ");
        }

        if(respuesta=='s')
        {
            listaC[i].estado=-2;
            ret=1;
            mostrarListaDeClientes(listaC,tam);
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

int mostrarOrdenClientes(eCliente listaC[],int tam)
{
    int i;
    int j;
    int ret=-1;
    eCliente aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(listaC[i].estado==1 && listaC[i].estado==1)
            {
                if(strcmp(listaC[i].nombre,listaC[j].nombre)<0)
                {
                    aux=listaC[i];
                    listaC[i]=listaC[j];
                    listaC[j]=aux;
                    ret=1;
                }
                if(strcmp(listaC[i].apellido,listaC[j].apellido)<0)
                {
                    aux=listaC[i];
                    listaC[i]=listaC[j];
                    listaC[j]=aux;
                }
            }
        }
    }

    mostrarListaDeClientes(listaC,tam);

    return ret;
}
