#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
#include "juegos.h"
#include "cliente.h"

typedef struct
{
    int idAlquiler;
    int cliente;
    int juego;
    char fecha[10];
    int estado;
}eAlquiler;

#endif // ALQUILER_H_INCLUDED

int menu();
int getInt(char []);
char getString(char [],char [],char []);
float getDec(char [],char []);
char getChar(char [],char []);
int esNumerica(char* );
int esLetra(char* );
int esDecimal(char* );
int esDomicilio(char* );
int esFecha(char* );
int iniciarAlquiler(eAlquiler [],int );
int iniciarAlquilerHardcode(eAlquiler []);
int mostrarListaDeAlquiler(eAlquiler [], int);
int mostrarAlquiler(eAlquiler );
int buscarLibreAlquiler(eAlquiler [],int );
int autoIdAlquiler(eAlquiler [],int );
int altaAlquiler(eAlquiler [],int ,eJuegos [],int ,eCliente [],int );
