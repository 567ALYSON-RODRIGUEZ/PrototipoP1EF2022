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

//Metodos atributo apellido del cliente
string ClsClientes::mobtenerApellidoC() const
{
    return m_sapellidoCliente;
}

void ClsClientes::mestablecerApellidoC( string scadenaApellidoC )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorApellidoC = scadenaApellidoC.data();
   int ilongitud = strlen( svalorApellidoC );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_sapellidoCliente, svalorApellidoC, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sapellidoCliente[ ilongitud ] = '\0';
}

//Metodos atributos reserva del cliente
string ClsClientes::mobtenerReservaC() const
{
    return m_sReservaCliente;
}

void ClsClientes::mestablecerResevaC( string scadenaResevaC )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorReservaC = scadenaResevaC.data();
   int ilongitud = strlen( svalorReservaC );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_sReservaCliente, svalorReservaC, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sReservaCliente[ ilongitud ] = '\0';
}

//Metodos atributos compra del cliente
string ClsClientes::mobtenerCompraC() const
{
    return m_sCompraCliente;
}

void ClsClientes::mestablecerCompraC( string scadenaCompraC )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorCompraC = scadenaCompraC.data();
   int ilongitud = strlen( svalorCompraC );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_sCompraCliente, svalorCompraC, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sCompraCliente[ ilongitud ] = '\0';
}

//Metodos atributo correo del cliente
string ClsClientes::mobtenerCorreoC() const
{
    return m_sCorreoCliente;
}

void ClsClientes::mestablecerCorreoC( string scadenaCorreoC )
{
   // copiar a lo más 20 caracteres de la cadena
   const char *svalorCorreoC = scadenaCorreoC.data();
   int ilongitud = strlen( svalorCorreo );
   ilongitud = ( ilongitud < 30 ? ilongitud : 29 );
   strncpy( m_sCorreoCliente, svalorCorreoC, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_sCorreoCliente[ ilongitud ] = '\0';
}

//Metodos del CRUD de clientes
ClsClientes::mcrearClientes()
{
    ofstream archivoClientes("registrosclientes.dat", ios::out | ios::binary);
    if(!archivoClientes)
    {
        cerr<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    ClsClientes clienteEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoClientes.write(reinterpret_cast<const char * > (&clinteEnBlanco), sizeof(ClsClientes));
    }
}

int ClsClientes::mobtenerIndicadorC(const char * const iindicador)
{
    int m_iclaveCliente;

   // obtener el valor del número de cliente
   do {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iclaveCliente;

   } while ( m_iclaveCliente < 1 || m_iclaveCliente > 100 );

   return m_iclaveCliente;
}

void ClsClientes::mnuevoCliente(fstream &archivoClientes)
{
   ClsClientes clientes;
   int m_iclaveCliente = mobtenerIndicadorC( "Escriba el numero de cliente" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoClientes.seekg(
      ( m_iclaveCliente - 1 ) * sizeof( ClsClientes ) );

   // leer el registro del archivo
   archivoClientes.read( reinterpret_cast< char * >( &clientes ),
      sizeof( ClsClientes ) );

    // crear el registro, si éste no existe ya
   if ( clientes.mobtenerClaveC() == 0 ) {

      char m_snombreCliente[ 10 ];

      // el usuario introduce el nombre
      cout << "Escriba el nombre del cliente: " << endl;
      cin >> setw( 10 ) >> m_snombreCliente;
      cout << "Escriba el apellido del cliente:" << endl;
      cin >> setw( 10 ) >> m_sapellidoCliente ;
      cout << "Escriba el tipo de reserva del cliente (Activo/Desactivo):" << endl;
      cin >> setw( 10 ) >>m_sReservaCliente;
      cout << "Escriba el nombre de la compra del cliente:" << endl;
      cin >> setw( 20 ) >>m_sCompraCliente;
      cout << "Escriba el correo electronico del cliente:" << endl;
      cin >> setw( 20 ) >> m_sCorreoCliente;

      // usar valores para llenar los valores de la clave
      clientes.mestablecerClaveCliente( m_iclaveCliente );
      clientes.mestablecerNombreC( m_snombreCliente );
      clientes.mestablecerApellidoC(m_sapellidoCliente);
      clientes.mestablecerResevaC(m_sReservaCliente);
      clientes.mestablecerCompraC(m_sCompraCliente);
      clientes.mestablecerCorreoC(m_sCorreoCliente);

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoClientes.seekp( ( m_iclaveCliente - 1 ) *
         sizeof( ClsClientes ) );

      // insertar el registro en el archivo
      archivoClientes.write(
         reinterpret_cast< const char * >( &clientes ),
         sizeof( ClsClientes ) );

        cout << "Cliente agregada con exito.";

   }
}

void ClsClientes::mostrarLineaClientes( const ClsClientes &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerClaveC()
          << setw( 10 ) << registro.mobtenerNombreC().data()
          << setw( 10 ) << registro.mobtenerApellidoC().data()
          << setw( 10 ) << registro.mobtenerReservaC().data()
          << setw( 20 ) << registro.mobtenerCompraC().data()
          << setw( 20 ) << registro.mobtenerCorreoC().data()
          << endl;
}


ClsClientes::~ClsClientes()
{
    //dtor
}
