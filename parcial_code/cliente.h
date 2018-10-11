#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char sexo;
    char domicilio[51];
    int estado;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int iniciarClientes(eCliente [],int );
int iniciarClientesHardcode(eCliente []);
int mostrarListaDeClientes(eCliente [], int);
int mostrarClientes(eCliente );
int menuClientes();
int buscarLibreClientes(eCliente [],int );
int autoIdClientes(eCliente [],int );
int altaClientes(eCliente [],int );
int buscarIdClientes(eCliente [],int );
int repeticionClientes(eCliente [],char [],char [],int );
int modificacionClientes(eCliente [],int );
int bajaClientes(eCliente [],int );
int mostrarOrdenClientes(eCliente [],int );
