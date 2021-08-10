/* ARCHIVOS BINARIOS */  
/* ACCESO RANDOM */  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};


void MODIFICAR (){
		FILE * FP;
		struct ALUMNO X;
		int edad;
		char nombre[30];
		int dist;
		int cont = 0;

		if ((FP = fopen ("BD","r+b")) == NULL ){
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);	
		}
		
		//printf("\n\nIngrese el nombre de la persona que desea editar: ");
		//gets(nombre);
				

		fread(&X , sizeof(X) , 1 , FP);
		
		while(!feof(FP)){
		    if(X.SEX == 'F'){
			X.EDAD = 2*X.EDAD;
            
            fseek(FP, (long)(-1)*sizeof(X) , SEEK_CUR);
            
			fwrite(&X , sizeof(X) ,1 , FP);
		    fseek(FP, 0L, SEEK_CUR);
		    }
			fread(&X , sizeof(X) , 1 , FP);	   
		}
            
	fclose(FP);	
}


void LEER(){
		FILE * FP ;
		struct ALUMNO X ;

		if ( (FP = fopen ("BD","r")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);	
		}
		
	
	    printf("\n\n\t %-20s %10s %10s\n\n" ,"NOMBRE","SEXO","EDAD");
		fread ( &X , sizeof(X) , 1 , FP );
		while (!feof(FP)){
				printf("\n\n\t %-20s %10c %10d" ,
				X.NOM , X.SEX , X.EDAD );
				fread ( &X , sizeof(X) , 1 , FP );
		}
		printf("\n\n");	
}



int main(){
	    LEER();
	    MODIFICAR();
		LEER();
	
	return 0;
}

