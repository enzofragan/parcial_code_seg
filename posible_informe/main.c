#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*void mostrarPropietarioPorNombre(ePropietario listaP[],int tamanioP)
    {
        int opcion;
        ePropietario aux;
        int i;
        int j;
        printf("\n1-ascendiente");
        printf("\n0-descendiente\n");
        opcion=getInt("ingrese una opcion valida ",opcion);
        if(opcion==1)
        {
            for(i=0; i<tamanioP-1; i++)
            {
                for(j=i+1; j<tamanioP; j++)
                {
                    if(strcmp(listaP[i].nombre,listaP[j].nombre)>0)
                    {
                        aux=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=aux;
                    }
                }
            }
            mostrarListaDePropietario(listaP,tamanioP);
        }
        else if(opcion==0)
        {
            for(i=0; i<tamanioP-1; i++)
            {
                for(j=i+1; j<tamanioP; j++)
                {
                    if(strcmp(listaP[i].nombre,listaP[j].nombre)<0)
                    {
                        aux=listaP[i];
                        listaP[i]=listaP[j];
                        listaP[j]=aux;
                    }
                }
            }
            mostrarListaDePropietario(listaP,tamanioP);
        }
        else
        {
            printf("\nOpcion no encontrada\n");
        }
    }*/

   /* void mostrarPropietariosSuperanEdad(ePropietario listaP[],int tamanioP)
    {
        int contador=0;
        int edad;
        printf("Ingresa la edad a superar ")
        edad=getInt("Ingresa una edad valida",edad);
        printf("\nid\tnombre\t  tarjeta\t\tdireccion\tedad\n");
        int i;
        for(i=0;i<tamanioP;i++)
        {
            if(listaP[i].edad>edad&&listaP[i].estado==1)
            {
                mostrarPropietario(listaP[i]);
                contador=contador+1;
            }
        }
        if(contador==0)
        {
            printf("\nno hay propietarios que superen la edad ingresada ");
        }
    }*/

   /* void mostrarRecaudaciones(eEgresado listaE[],int tamanioE)
    {

            float egresos=0;
            int i;
            for(i=0; i<tamanioE; i++)
            {
                if(listaE[i].estado==1)
                {
                    egresos+=listaE[i].recaudacion;
                }
            }
            printf("La recaudacion total del estacionamiento es de: $%.2f",egresos);

    }

    void mostrarRecaudacionesPorMarca(eEgresado listaE[],int tamanioE)
    {
            float alpha=0;
            float ferrari=0;
            float audi=0;
            float otro=0;
            int i;
            for(i=0; i<tamanioE; i++)
            {
                if(listaE[i].estado==1)
                {
                    if(listaE[i].marca==1)
                    {
                        alpha+=listaE[i].recaudacion;
                    }
                    else if(listaE[i].marca==2)
                    {
                        ferrari+=listaE[i].recaudacion;
                    }
                    else if(listaE[i].marca==3)
                    {
                        audi+=listaE[i].recaudacion;
                    }
                    else
                    {
                        otro+=listaE[i].recaudacion;
                    }

                }
            }
            printf("\nRecaudacion de los coches pertenecientes a la marca Alfa Romeo: $%.2f",alpha);
            printf("\nRecaudacion de los coches pertenecientes a la marca Ferrari: $%.2f",ferrari);
            printf("\nRecaudacion de los coches pertenecientes a la marca Audi: $%.2f",audi);
            printf("\nRecaudacion de los coches pertenecientes a otras marcas: $%.2f",otro);

    }*/

    /*void mostrarUsuarioConSusAutomoviles(ePropietario listaP[],eAuto listaA[],int tamanioP,int tamanioA)
    {

            int IdPropietario;
            int indice;
            int i;
            mostrarListaDePropietario(listaP,tamanioP);

            indice=buscarIdPropietario(listaP,tamanioP);
            if(indice!=-1)
            {
                printf("\npropietario: %s\n",listaP[indice].nombre);
                for(i=0; i<tamanioA; i++)
                {
                    if(listaP[indice].Id==listaA[i].idPropietario)
                    {
                        printf("\nmarca: %s",listaA[i].marcaNombre);
                        printf("\npatente: %s\n",listaA[i].patente);
                    }
                }
            }
            else
            {
                printf("\npropietario no encontrado\n");
            }

    }*/

    /*void mostrarPropietarioAudi(ePropietario listaP[],eAuto listaA[],int tamanioP,int tamanioA)
    {

            int i;
            int j;
            int flag=0;
            printf("\n\npropietarios con un coche marca Audi\n");
            printf("ID\tNombre\tTarjeta de credito\tDireccion\n");
            for(i=0; i<tamanioA; i++)
            {
                if(listaA[i].estado==1 && listaA[i].marca==3)
                {
                    for(j=0; j<tamanioP; j++)
                    {
                        if(listaA[i].idPropietario==listaP[j].Id && listaP[j].estado==1)
                        {
                            flag=flag+1;
                            printf("%d\t%s\t  %s\t\t%s\n",listaP[j].Id,listaP[j].nombre,listaP[j].tarjeta,listaP[j].direccion);
                        }
                    }
                }
            }
            if(flag==0)
            {
                printf("\nNo hay propietarios que tengan estacionado un coche marca AUDI");
            }
    }*/

   /* void mostrarOrdenadosPorPatente(ePropietario listaP[],eAuto listaA[],int tamanioP,int tamanioA)
    {

            eAuto aux;
            eAuto auxOrdenada[tamanioA];
            transefrirDatos(listaA,auxOrdenada,tamanioA);
            int largo;
            int i;
            int j;
            for(i=0; i<tamanioA-1; i++)
            {
                for(j=i+1; j<tamanioA; j++)
                {
                    if(strcmp(auxOrdenada[i].patente,auxOrdenada[j].patente)>0)
                    {
                        aux=auxOrdenada[i];
                        auxOrdenada[i]=auxOrdenada[j];
                        auxOrdenada[j]=aux;
                    }
                }
            }
            printf("Id ingreso\tPatente\t  Marca\t\t   Propietario  Id Propietario \n");
            for(i=0; i<tamanioA; i++)
            {
                if(auxOrdenada[i].estado==1)
                {
                    for(j=0; j<tamanioP; j++)
                    {
                        if(auxOrdenada[i].idPropietario==listaP[j].Id&&listaP[j].estado==1)
                        {
                            largo=strlen(listaP[j].nombre);
                            cambiarMarcas(auxOrdenada,auxOrdenada[i].marca,auxOrdenada[i].marcaNombre);
                            printf("\n%d\t\t%s\t  %s\t   %s\t\t",auxOrdenada[i].idIngreso,auxOrdenada[i].patente,auxOrdenada[i].marcaNombre,listaP[j].nombre);
                            if(largo<5)
                            {
                                printf("\t");
                            }
                            printf("%d",listaP[j].Id);
                        }
                    }
                }
            }

    }

    void transefrirDatos(eAuto listaA[],eAuto aux[],int tamanioA)
    {
        int i;
        for(i=0;i<tamanioA;i++)
        {
            if(listaA[i].estado==1)
            {
                aux[i].estado=listaA[i].estado;
                aux[i].idIngreso=listaA[i].idIngreso;
                aux[i].idPropietario=listaA[i].idPropietario;
                aux[i].marca=listaA[i].marca;
                strcpy(aux[i].marcaNombre,listaA[i].marcaNombre);
                strcpy(aux[i].patente,listaA[i].patente);
            }
        }
    }*/

    return 0;
}
