#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int idJuedo;
    char descripcion[51];
    int importe;
    int estado;
}eJuegos;

#endif // JUEGOS_H_INCLUDED

int iniciarJuegos(eJuegos [],int );
int iniciarJuegosHardcode(eJuegos []);
int mostrarListaDeJuegos(eJuegos[], int);
int mostrarJuegos(eJuegos );
int menuJuegos();
int buscarLibreJuegos(eJuegos [],int );
int autoIdJuegos(eJuegos [],int );
int altaJuegos(eJuegos [],int );
int buscarIdJuego(eJuegos [],int );
int repeticionJuego(eJuegos [],char [],int );
int modificacionJuego(eJuegos [],int );
int bajaJuego(eJuegos [],int );
int mostrarOrdenJuegos(eJuegos [],int );
