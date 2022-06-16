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



ClsClientes::~ClsClientes()
{
    //dtor
}
