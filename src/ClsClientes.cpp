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

void ClsClientes::mconsultarRegistroClientes(fstream &archivoClientes)
{
   cout << left << setw( 10 ) << "Clave" << setw( 10 )
       << "Nombre" << setw( 10 ) << "Apellido"<<setw( 10 )<<
       "Reserva"<<setw( 20 )<< "Compra"<<setw( 20 )<< "Correo"<<endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoClientes.seekg( 0 );

   // leer el primer registro del archivo de registros
   ClsClientes clientes;
   archivoClientes.read( reinterpret_cast< char * >( &clientes ),
      sizeof( ClsClientes ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoClientes.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( clientes.mobtenerClaveC() != 0 )
         mostrarLineaClientes(clientes);

      // leer siguiente registro del archivo de registros
      archivoClientes.read( reinterpret_cast< char * >( &clientes ),
         sizeof( ClsClientes ) );

   }
}

void ClsClientes::mmostrarLineaRegistroClientes( ostream &salida, const ClsClientes &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClaveC()
          << setw( 10 ) << registro.mobtenerNombreC().data()
          << setw( 10 ) << registro.mobtenerApellidoC().data()
          << setw( 10 ) << registro.mobtenerReservaC().data()
          << setw( 20 ) << registro.mobtenerCompraC().data()
          << setw( 20 ) << registro.mobtenerCorreoC().data()
          << endl;
}

void ClsClientes::mmodificarRegistroClientes( fstream &archivoClientes)
{
   ClsClientes clientes;
   int m_iclaveCliente= mobtenerIndicadorC("Ingrese el nombre del cliente");

   archivoClientes.seekg(
      ( m_iclaveCliente - 1 ) * sizeof( ClsClientes ) );

   // leer el primer registro del archivo
   archivoClientes.read( reinterpret_cast< char * >( &clientes ),
      sizeof( ClsEmpresa ) );

   // actualizar el registro
   if ( clientes.mobtenerClaveC() != 0 ) {
      mmostrarLineaRegistroClientes( cout, clientes );

      cout << "\nEscriba el nombre: ";
      char m_snombreCliente [ 10 ];
      cin >> m_snombreCliente;

      cout << "Escriba el apellido del cliente:";
      char m_sapellidoCliente [ 10 ];
      cin >> m_sapellidoCliente;

      cout << "Escriba el tipo de reserva del cliente (Activo/Desactivo):";
      char m_sReservaCliente [ 10 ];
      cin >> m_sReservaCliente;

      cout << "Escriba el nombre de la compra del cliente:";
      char m_sCompraCliente [ 20 ];
      cin >> m_sCompraCliente;

      cout << "Escriba el correo del cliente:";
      char m_sCorreoCliente [ 20 ];
      cin >> m_sCorreoCliente;

      // actualizar el saldo del registro
      clientes.mestablecerNombreC( m_snombreCliente );
      mmostrarLineaRegistroClientes( cout, clientes );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoClientes.seekp(
         ( m_iclaveCliente - 1 ) * sizeof( ClsClientes ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoClientes.write(
         reinterpret_cast< const char * >( &clientes ),
         sizeof( ClsClientes ) );

        cout << "Cliente modificado con éxito.";

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La clave #" << m_iclaveCliente
         << " no tiene informacion." << endl;
}

void ClsClientes::mimprimirRegistroClientes(fstream &archivoClientes)
{
    ClsClientes clientes;
    ofstream imprimir("registrodeclientes.txt", ios::out);

   // salir del programa si ofstream no puede crear el archivo
   if ( !imprimir ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   imprimir << left << setw( 10 ) << "Clave" << setw( 10 )
       << "Nombre: " << setw( 10 ) << "Apellido"<<setw( 10 )<<
       "Reserva"<<setw( 20 )<< "Compra"<<setw( 20 )<< "Correo"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoClientes.seekg( 0 );

   // leer el primer registro del archivo de registros
   archivoClientes.read( reinterpret_cast< char * >( &clientes),
      sizeof( ClsClientes ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoClientes.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( clientes.mobtenerClaveC() != 0 )
         mmostrarLineaRegistroClientes( imprimir, clientes );

      // leer siguiente registro del archivo de registros
      archivoClientes.read( reinterpret_cast< char * >( &clientes ),
         sizeof( ClsClientes ) );

   }
   cout << "archivo creado con éxito con el nombre de: registroclientes";
}

void ClsClientes::meliminarRegistroClientes(fstream &archivoClientes)
{
    int iindicador= mobtenerIndicadorC( "Escriba la clave del cliente a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoClientes.seekg(
      ( iindicador - 1 ) * sizeof( ClsClientes ) );

   // leer el registro del archivo
   ClsClientes clientes;
   archivoClientes.read( reinterpret_cast< char * >( &clientes ),
      sizeof( ClsClientes ) );

   // eliminar el registro, si es que existe en el archivo
   if ( clientes.mobtenerClaveC() != 0 ) {
      ClsClientes clientesEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoClientes.seekp( ( iindicador - 1 ) *
         sizeof( ClsClientes) );

      // reemplazar el registro existente con un registro en blanco
      archivoClientes.write(
         reinterpret_cast< const char * >( &clientesEnBlanco ),
         sizeof( ClsClientes) );

      cout << "Cliente clave #" << iindicador << " eliminado correctamente.\n";
   }
}

void ClsClientes::mbuscarClientes(fstream &archivoClientes)
{
    int iindicador = mobtenerIndicadorC( "Escriba la clave del cliente que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoClientes.seekg(
      ( iindicador - 1 ) * sizeof( ClsClientes ) );

   // leer el primer registro del archivo
   ClsClientes clientes;
   archivoClientes.read( reinterpret_cast< char * >( &clientes),
      sizeof( ClsClientes ) );

   // actualizar el registro
   if ( clientes.mobtenerClaveC() != 0 ) {
      mmostrarLineaRegistroClientes( cout, clientes);
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "La clave #" << iindicador
         << " no tiene informacion." << endl;
   }
   getch();
}

ClsClientes::mmenuClientes()
{
    int iseleccionMenuClientes;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoClientes("registrosclientes.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoClientes)
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearClientes();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION CLIENTES  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Cliente"<<endl;
        cout<<"2. Despliegue Cliente"<<endl;
        cout<<"3. Modifica Cliente"<<endl;
        cout<<"4. Imprimir Regisro de Cliente"<<endl;
        cout<<"5. Borra Cliente"<<endl;
        cout<<"6. Buscar Cliente"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuClientes;
        switch(iseleccionMenuClientes)
        {
        case 1:
            {
                system("cls");
                mnuevoCliente(archivoClientes);
                getch();
            }
            break;
        case 2:
            {
                system("cls");
                mconsultarRegistroClientes(archivoClientes);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                system("cls");
                mmodificarRegistroClientes(archivoClientes);
                getch();
            }
            break;
        case 4:
            {
                system("cls");
                mimprimirRegistroClientes(archivoClientes);
                getch();
            }
            break;
        case 5:
            {
                system("cls");
                meliminarRegistroClientes(archivoClientes);
            }
            break;
        case 6:
            {
                system("cls");
                mbuscarClientes(archivoClientes);
            break;
        case 0:
            break;
        default:
            cout<<"Opción invalida, intenta de nuevo";
            getch();
            break;
        }
    }while(iseleccionMenuClientes!=0);
}

ClsClientes::~ClsClientes()
{
    //dtor
}
