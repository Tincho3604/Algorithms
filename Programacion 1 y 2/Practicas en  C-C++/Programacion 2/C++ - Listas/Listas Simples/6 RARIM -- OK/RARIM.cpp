/* LISTAS SIMPLEMENTE ENLAZADAS */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

class NODO {
		public :
			char NOM[20] ;
			NODO * SIG ;
			NODO ( char * );
			~NODO() ;
};


NODO::NODO(char * S)
{
		strcpy ( NOM , S );
}

NODO::~NODO()
{
		cout << "\n\n   MATANDO A .... " << NOM << "\n";
		getchar() ;
}


class LISTA {
		private :
			NODO * INICIO ;
			void PONER_P(NODO *);
			void PONER_F(NODO *);
		public :
			LISTA() ;
			~LISTA() ;
			void AGREGAR_P(char *) ;
			void RARIM(int) ;
			void AGREGAR_F(char *);
			void MIRAR() ;
};


LISTA::LISTA()
{
		INICIO = NULL ;
}

LISTA::~LISTA()
{
		cout << "\n\n   DESTRUYENDO TODOS LOS NODOS \n";
		cout << "\n\n   ESTA ES PARA USTEDES !!! .... \n";
		getchar() ;
}


void LISTA::AGREGAR_P(char * S)
{
		NODO * P ;
		P = new NODO(S) ;
	
		PONER_P(P) ;
}

void LISTA::PONER_P(NODO * PN)
{
		PN->SIG = INICIO ;
		INICIO = PN ;
}

void LISTA::AGREGAR_F(char * S)
{
		NODO * P ;
		P = new NODO(S) ;
	
		PONER_F(P) ;
}

void LISTA::PONER_F(NODO * PN)
{
		NODO * P ;
		
		P = INICIO ;		
		PN->SIG = NULL ;
		
		if ( ! INICIO ) {
				/*  LISTA VACIA  */
				INICIO = PN ;
				return ;
		}
		/*  LISTA NO VACIA  */
		while ( P->SIG )
				P = P->SIG ; 	// LLEVO P HASTA EL ULTIMO NODO
		P->SIG = PN ;		
}



void LISTA::RARIM(int N){
   NODO * P;
   P = INICIO ;
   char * arr[N];
   int i;
   int j;
      
   cout << "\n\n\n\t ------ CONTENIDO DE LA LISTA RARIM --------- \n\n";
   for(i=0; i<N; i++) {
       arr[i] = P->NOM;
   	   P = P->SIG ;
   }
     
   for(j=N-1; j>=0; --j){ 
       cout<<"\n\n\n\t NOMBRES AL REVEZ:  "<<arr[j];
   }
 
   
}


void LISTA::MIRAR()
{
		NODO * P ;
		cout << "\n\n\n\t CONTENIDO DE LA LISTA \n\n";
		int cont = 0;
		
		P = INICIO ;
		while (P) {
				cout << "\n\n\t " << P->NOM ;
				P = P->SIG ;
				cont++;			
		}
		
		RARIM(cont);
		getchar();		
}

int main()
{
		LISTA L ;
		char BUF[20] ;
		
		cout << "\n\n   NOMBRE   :   ";
		cin >> BUF ;
		while ( strcmp(BUF,"FIN") ) {
				L.AGREGAR_F(BUF) ;
			
				cout << "\n\n   NOMBRE   :   ";
				cin >> BUF ;
		}
		
		L.MIRAR() ;
											
		printf("\n\n\n\n FIN DEL PROGRAMA\n\n");
		return 0 ;
}



