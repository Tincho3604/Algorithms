/* ARCHIVOS BINARIOS */  
/* ALTAS EN UN ARCHIVO BINARIO */  

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};

#define N 4

int main()
{
		FILE * FP ;
		struct ALUMNO X ;
		int I ;
		
		if ( (FP = fopen ("BD","ab")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		for ( I = 0 ; I < N ; I++ ) {
				fflush(stdin);
				printf("\n\n\t  NOMBRE  :  ");
				gets(X.NOM);
				printf("\n\t  SEXO    :  ");
				X.SEX = getchar();
				printf("\n\t  EDAD    :  ");
				scanf("%d" , &(X.EDAD) );
				
				fwrite ( &X , sizeof(X) , 1 , FP );
		}
				
		fclose(FP);
		
		return 0 ;
}
