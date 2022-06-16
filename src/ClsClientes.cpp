#include "ClsClientes.h"
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

using namespace std;

ClsClientes::ClsClientes(int iclaveCliente, string snombreCliente, string sapellidoCliente, string sresevaCliente, string scompreCliente, string scorreoCliente);
{
    //ctor
    mestablecerClaveCliente(iclaveCliente);
    mestablecerNombreC(snombreCliente);
    mestablecerApellidoC(sapellidoCliente);
    mestablecerReservaC(sreservaCliente);
    mestablecerCompraC(scompraCliente);
    mestablecerCorreoC(scorreoCliente);
}

//Metodos del atributo clase clientes
int ClsClientes::mobtenerClaveC() const
{
    return int m_iclaveCliente;
}

void ClsClientes::mestablecerClaveCliente (int ienteroClaveC)
{
    m_iclaveCliente = ienteroClaveC;
}

//Metodos atributo nombre del cliente
string ClsClientes::mobtenerNombreC() const
{
    return m_snombreCliente;
}

void ClsClientes::mestablecerNombreC( string scadenaNombreC )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorNombreC = scadenaNombreC.data();
   int ilongitud = strlen( svalorNombreC );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_snombreCliente, svalorNombreC, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombreCliente[ ilongitud ] = '\0';
}


ClsClientes::~ClsClientes()
{
    //dtor
}
