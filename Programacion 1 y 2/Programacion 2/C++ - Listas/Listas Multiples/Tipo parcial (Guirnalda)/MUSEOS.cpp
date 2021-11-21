#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

class Visitante {
	public:
			char NOM [20];
			Visitante * SIG;
};

Visitante::Visitante(char * S){
	 
}

class Museo {
	public:
			char NOM [20];
			Visitante * PVIS;
			Museo * SIG;
};


class RegistroVisitas {	
	public:
			Museo * INICIO;

};





int main() {          
	RegistroVisitas * lista = new RegistroVisitas;
	
	//lista->nuevoMuseo("MALBA");
	//lista->nuevoMuseo("MUSEO HISTORICO NAC.");
	//lista->nuevoMuseo("MUSEO DE CS. NATURALES");
	
	//lista->registrarVisita("MALBA", "Pepe"); 
	//lista->registrarVisita("MUSEO HISTORICO NAC.", "Pepe"); 
	//lista->registrarVisita("MALBA", "Maria Alvarez"); 
	//lista->registrarVisita("MUSEO DE CS. NATURALES", "Pepe"); 
	//lista->registrarVisita("MUSEO DE CS. NATURALES", "Roberto Sanchez");
	
	//lista ->mirar();
	
	//lista->verVisitantesPerfectos(); 
	//lista->borrarMuseosMenosVisitados(); //borra el historico nacional
	
	//lista ->mirar();
	
return 0;
}
