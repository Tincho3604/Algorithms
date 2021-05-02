/* ARCHIVOS BINARIOS */  
/* ACCESO RANDOM */  

#include <stdio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};


int main()
{
		FILE * FP ;
		struct ALUMNO X ;
		int POS , A ;
				
		if ( (FP = fopen ("BD","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		printf("\n\n\t %-20s %10s %10s\n\n" ,"NOMBRE","SEXO","EDAD");
		A = fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				printf("\n\n\t %-20s %10c %10d \t %d" ,
				X.NOM , X.SEX , X.EDAD , A );
				
				A = fread ( &X , sizeof(X) , 1 , FP );
		}
				
		printf("\n\n  POSICION  = ");
		scanf("%d" , &POS) ;
		while ( POS >= 0 ) {
			fseek ( FP , (long)POS*sizeof(X) , SEEK_SET);
			A = fread ( &X , sizeof(X) , 1 , FP );
			printf("\n\n\t %-20s %10c %10d \t %d" ,
			X.NOM , X.SEX , X.EDAD , A );
			
			printf("\n\n  POSICION  = ");
			scanf("%d" , &POS) ;
		}
		
		fclose(FP);	
				
		printf("\n\n");
		return 0 ;
}
