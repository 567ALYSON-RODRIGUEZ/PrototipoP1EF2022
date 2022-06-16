#ifndef CLSCLIENTES_H
#define CLSCLIENTES_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class ClsClientes
{
    public:
        ClsClientes(int = 0 , string = " ", string = " ", string = " ", string = " ", string = " ", string = " " );

        mmenuClientes();
        mcrearClientes();

        int mobtenerIndicadorC( const char * const );

        void mnuevoCliente(fstream &archivoClientes);

        void mconsultarRegistroClientes(fstream &archivoClientes);

        void mostrarLineaClientes( const ClsClientes &registro );

        void mmodificarRegistroClientes( fstream &archivoClientes );

        void mmostrarLineaRegistroClientes( ostream &salida, const ClsClientes &registro );

        void mimprimirRegistroClientes(fstream &archivoClientes);

        void meliminarRegistroClientes(fstream &archivoClientes);

        void mbuscarClientes(fstream &archivoClientes);

        void mestablecerClaveCliente( int ) ;
        int mobtenerClaveC() const;

        void mestablecerNombreCliente string );
        string mobtenerNombreC() const;

        void mestablecerApellidoC(string);
        string mobtenerApellidoC()const;

        void mestablecerTelefonoC(string);
        string mobtenerTelefonoC()const;

        void mestablecerResevaC(string);
        string mobtenerReservaC()const;

        void mestablecerCompraC(string);
        string mobtenerCompraC()const;

        void mestablecerCorreoC(string);
        string mobtenerCorreoC()const;

        virtual ~ClsClientes();

    protected:

    private:
        int m_iclaveCliente;
        char m_snombreCliente[10];
        char m_sapellidoCliente[ 10 ];
        char m_sTelefonoCliente[9];
        char m_sReservaCliente[10];
        char m_sCompraCliente[20];
        char m_sCorreoCliente[20];

};

#endif // CLSCLIENTES_H
