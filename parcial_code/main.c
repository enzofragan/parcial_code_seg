#include <stdio.h>
#include <stdlib.h>
#include "alquiler.h"
#define TAMJ 20
#define TAMC 20
#define TAMA 20

int main()
{
    eJuegos juego[TAMJ];
    eCliente cliente[TAMC];
    eAlquiler alquiler[TAMA];
    int opcion;
    int resultado;
    int registro=-1;
    int game=-1;
    int client=-1;
    char seguir='s';
    int altaJ;
    int modiJ;
    int bajaJ;
    int altaC;
    int modiC;
    int bajaC;

    game=iniciarJuegos(juego,TAMJ);
    game=iniciarJuegosHardcode(juego);

    client=iniciarClientes(cliente,TAMC);
    client=iniciarClientesHardcode(cliente);

    registro=iniciarAlquiler(alquiler,TAMA);
    //iniciarSeriesUsuariosHardcode(usuarioseries);

    if(registro>0)
    {
       do
        {
            //system("cls");
            opcion=menu();

            switch(opcion)
            {
            case 1:
                if(game>0)
                {
                    do
                    {
                       // system("cls");
                        resultado=menuJuegos();
                        switch(resultado)
                        {
                        case 1:
                            altaJ=altaJuegos(juego,TAMJ);
                            if(altaJ==0)
                            {
                                printf("\nse ingreso el juego correctamente \n\n");
                            }
                            else
                            {
                                printf("\ningreso cancelado \n\n");
                            }
                            break;
                        case 2:
                            modiJ=modificacionJuego(juego,TAMJ);
                            if(modiJ>0)
                            {
                                printf("\nse a modificado el juego correctamente \n\n");
                            }
                            else
                            {
                                printf("\nmodificacion cancelada \n\n");
                            }
                            break;
                        case 3:
                            bajaJ=bajaJuego(juego,TAMJ);
                            if(bajaJ>0)
                            {
                                printf("\nse a dado de baja el juego correctamente \n\n");
                            }
                            else
                            {
                                printf("\nbaja cancelada \n\n");
                            }
                            break;
                        case 4:
                            mostrarListaDeJuegos(juego,TAMJ);
                            break;
                        }

                    }while(resultado<5);
                }
                else
                {
                    printf("inicie un lista primero\n");
                }
                break;
            case 2:
                if(client>0)
                {
                    do
                    {
                       // system("cls");
                        resultado=menuClientes();
                        switch(resultado)
                        {
                        case 1:
                            altaC=altaClientes(cliente,TAMC);
                            if(altaC==0)
                            {
                                printf("\nse ingreso el cliente correctamente \n\n");
                            }
                            else
                            {
                                printf("\ningreso cancelado \n\n");
                            }
                            break;
                        case 2:
                            modiC=modificacionClientes(cliente,TAMC);
                            if(modiC>0)
                            {
                                printf("\nse a modificado el cliente correctamente \n\n");
                            }
                            else
                            {
                                printf("\nmodificacion cancelada \n\n");
                            }
                            break;
                        case 3:
                            bajaC=bajaClientes(cliente,TAMC);
                            if(bajaC>0)
                            {
                                printf("\nse a dado de baja el cliente correctamente \n\n");
                            }
                            else
                            {
                                printf("\nbaja cancelada \n\n");
                            }
                            break;
                        case 4:
                            mostrarListaDeClientes(cliente,TAMC);
                            break;
                        }

                    }while(resultado<5);
                }
                else
                {
                    printf("inicie un lista primero\n");
                }
                break;
            case 4:
                seguir='n';
                break;
            }

        }while(seguir=='s');
    }
    else
    {
        printf("inicie la lista primero");
    }
    return 0;
}
