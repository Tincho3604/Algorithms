#include <stdio.h>
#include <string.h>

class Auto {
    public:
    char modelo[30];
    int anio;
    Auto * sig;

};

class Cliente {
    public:
    char nombre[30];
    char telefono[20];
    Cliente * sig;
    Auto * primerauto;


};

class ListaClientes {
    private:
    Cliente * inicio;


};


int main() {
    ListaClientes * lc = new ListaClientes;  // la guirnalda en sí

    lc->agregar("Pepe", "4555-6565");  //agrega Cliente (lista principal)
    lc->agregar("Maria", "4444-3232");
    lc->agregar("Carlos", "5460-1111");

    lc->buscar("Pepe")->agregarAuto("Renault 12", 1980);  //agrega Auto a un Cliente (lista secundaria)
    lc->buscar("Pepe")->agregarAuto("Renault Fluence", 2013);

    printf("\n Pepe tiene %d autos" , lc->buscar("Pepe")->cantAutos() );  //debe dar 2

    lc->buscar("Pepe")->vaciarAutos();

    printf("\n Pepe tiene %d autos" , lc->buscar("Pepe")->cantAutos() );  //debe dar 0
    
    printf("\n La guirnalda tiene %d clientes" , lc->cantClientes() );  //debe dar 3

}
