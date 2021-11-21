/*

Se cuenta con una clase Hospital que posee una lista enlazada de
objetos Medico. Cada Medico tiene a su vez una lista de Paciente.

Se pide:
--------

1) Declarar las 3 clases

2) Escribir el método 

		void Hospital::medicosDelPaciente(char *) 

que recibe el nombre de un Paciente y muestra en pantalla todos 
los médicos con quienes se atiende.



3) Escribir el método 

		Medico * Hospital::medicoConMenosPacientes(void) 

que retorna un puntero al Medico que menos pacientes tenga.
Se sabe que los médicos tienen siempre pacientes, al menos uno.


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


class PACIENTE {
	public:
		PACIENTE();
		~PACIENTE();
		char NOM[20];
		PACIENTE * SIG;
};



class MEDICO {
    public:
	  MEDICO(char *, PACIENTE *);
	  ~MEDICO();
	  char NOM[20];
	  PACIENTE * PPAC;
	  MEDICO * SIG;
	  MEDICO * medicoConMenosPacientes(void);
};


  MEDICO::MEDICO(char * PAC, PACIENTE * PP) {
	 strcpy(NOM, PAC);
	 
	 // La direccion del paciente esta asociada a la direccion del primer paciente
	 PPAC = PP;
}


class HOSPITAL {
	private :
		MEDICO * INICIO;
		MEDICO * BUSCAR(char *);
	public : 
	    HOSPITAL();
	    ~HOSPITAL();
	    char NOM[20];
	    MEDICO * NMED;
	    MEDICO * SIG;
	    void ARREGLATE(char *);
};
 
 
 HOSPITAL::HOSPITAL() {
   INICIO = NULL;	
} 


  MEDICO * HOSPITAL::BUSCAR (char * M) {

    MEDICO * MED;
    MED = INICIO;
    
    while (MED) {
	   if( !strcmp(MED->SIG, M) ) return MED;
       MED = MED->SIG; 
  }
  return NULL;
}


  	
char * GENERAMEDICO();
char * GENERAPACIENTES();


int main () {
	
	HOSPITAL H;

	char BUF[20];
	srand(80);
	
	strcpy( BUF, GENERAPACIENTES() );
	while( strcmp(BUF, "FIN") ) {
		H.ARREGLATE(BUF);
		strcpy(BUF, GENERAPACIENTES() );
		
	}
	
	printf("\n\n");
	return 0;
}





char * GENERAPACIENTES() {
	static int I = 0 ;
	static char NOM[][20] = {"DARIO","CAROLINA","PEPE","LOLA",
						     "PACO","LUIS","MARIA","ANSELMO",
						  	 "ANA","LAURA","PEDRO","ANIBAL",
						     "PABLO","ROMUALDO","ALICIA","MARTA",
						     "MARTIN","TOBIAS","SAUL","LORENA","LUIS",
							 "ANDRES","KEVIN","LUCRECIA","RAUL",
							 "ENZO","BETO","HERMINDO","FELIPE",
							 "GUILLERMO","TATO","KARINA","AQUILES",
							 "MINERVA","OLGA","LALO","TATIANA",
							 "LILO","STICH","EMA","THELMA","ALICIA",
							 "LOUISE","BONNIE","CLYDE","ROMEO",
							 "JULIETA","VERONICA","JORGE","ALEJANDRO",
							 "ROCIO","FIN"};
	
	return NOM[I++] ;
}


char * GENERAMEDICO() {
	static char NOM[][20] = {"Dr. Alvarez","Dr. Perez","Dr. Argibay","Dr. Mauro",
						     "Dr. Carlos","Dr. Mario","Dr. Luis" };						 
	return NOM[rand()%7] ;
}
