/*  LA CLASE LISTA TIENE NODOS CON NOMBRE Y PUNTAJE DE PERSONALIDADES  */
/*  QUE COMPITEN EN UN CONCURSO DE POPULARIDAD  */
/*  LA CLASE LISTA NEGRA, TIENE VOTOS NEGATIVOS SOBRE CADA UNO DE LOS  */
/*  CANDIDATOS  */
/*  SE DEBE ACTUALIZAR LISTA HACIENDO QUE POR CADA VOTO NEGATIVO EN    */
/*  LISTANEGRA, SE LE DESCUENTE UN PUNTO AL CANDIDATO. EN CASO QUE ESTE */
/*  NO POSEA MAS PUNTOS, SE LO DEBE DAR DE BAJA  */
/*  CONSTRUIR LA FUNCION IMPUGNA(), CUYO PROTOTIPO SE ADJUNTA, DE FORMA */
/*  QUE REALICE LO PEDIDO */
/*  REALIZAR EL AGREGADO EN LAS CLASES QUE CONSIDERE CONVENIENTE  */


#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAX_VOTOS 15 

using namespace std ;

class CANDI {
	public :
		char NOM[20];
		int VOTOS ;
		CANDI * SIG ;
};

class LISTA {
	private :
		CANDI * INICIO ;
	public :
		LISTA() ;
		void MIRAR() ;
};

LISTA :: LISTA ()
{
	int I ;
	CANDI * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<16 ; I++ ) {
		P = new CANDI ;
		strcpy ( P->NOM , NOM [ I ] ) ;
		P->VOTOS = 1 + rand()% MAX_VOTOS ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
}

void LISTA :: MIRAR ()
{
	CANDI * P ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "     %-10s%5d" , P->NOM , P->VOTOS) ;
		P = P->SIG ;
	}
	getch();
}





class PERSONA {
	public :
		char NOM[20];
		PERSONA * SIG ;
};

class LISTANEGRA {
	private :
		PERSONA * INICIO ;
	public :
		LISTANEGRA() ;
		void MIRAR() ;
};

LISTANEGRA :: LISTANEGRA ()
{
	int I ;
	PERSONA * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<100 ; I++ ) {
		P = new PERSONA ;
		strcpy ( P->NOM , NOM [ rand()%16 ] ) ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
}

void LISTANEGRA :: MIRAR ()
{
	PERSONA * P ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "%-10s" , P->NOM ) ;
		P = P->SIG ;
	}
	getch();
}


/*  PROTOTIPO  */
void IMPUGNA ( LISTA & , LISTANEGRA & );


int main()
{
	LISTA L ;
	L.MIRAR() ;
	LISTANEGRA N ;
	N.MIRAR() ;

//	IMPUGNA ( L , N );

//	L.MIRAR() ;

	cout << "\n\n\nFIN DEL PROGRAMA  " ;
	getch();
	return 0 ;
}
