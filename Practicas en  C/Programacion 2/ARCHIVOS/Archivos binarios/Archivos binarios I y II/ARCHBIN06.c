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
		int POS , REF ;
				
		if ( (FP = fopen ("BD","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);			
		};
		
		printf("\n\n\t %-20s %10s %10s\n\n" ,"NOMBRE","SEXO","EDAD");
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				printf("\n\n\t %-20s %10c %10d" ,
				X.NOM , X.SEX , X.EDAD );
				
				fread ( &X , sizeof(X) , 1 , FP );
		}
				
		printf("\n\n  REFERENCIA y POSICION     ");
		scanf("%d %d" , &REF , &POS) ;
		while ( REF >= 0 ) {
			fseek ( FP , (long)POS*sizeof(X) , REF);
			fread ( &X , sizeof(X) , 1 , FP );
			printf("\n\n\t %-20s %10c %10d" ,
			X.NOM , X.SEX , X.EDAD );
			
			printf("\n\n  REFERENCIA y POSICION     ");
			scanf("%d %d" , &REF , &POS) ;
		}
		
		fclose(FP);	
				
		printf("\n\n");
		return 0 ;
}
