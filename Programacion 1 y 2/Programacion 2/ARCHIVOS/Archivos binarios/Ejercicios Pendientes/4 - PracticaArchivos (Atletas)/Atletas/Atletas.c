/*Se cuenta con un archivo ATLETAS, conteniendo registros con esta forma:
struct atleta {
		char NOMBRE[50];
		char PAIS[30];
		int ORO;
		int PLATA;
		int BRONCE;
};
Este archivo indica cuántas medallas ganó cada atleta en cierta edición de los Juegos Olímpicos.

Por otro lado, se cuenta con un archivo PAISES, con registros de esta forma:

struct pais {
		char NOMBRE[30];
		int ORO;
		int PLATA;
		int BRONCE;
};

El archivo PAISES está inicializado actualmente en cero, es decir, que todos los paises indican 0 medallas en las 3 categorías.


Se pide, en un solo programa:

1) Imprimir en pantalla los ATLETAS, para verificar que la lectura del archivo es correcta.

2) Actualizar el archivo PAISES para que refleje la cantidad de medallas obtenidas por cada país, sumadas, de acuerdo a los datos del archivo ATLETAS.

3) Mostrar en pantalla el archivo PAISES para corroborar los resultados.

4) Mostrar en pantalla el nombre del país que más medallas totales ganó, es decir, sumando las 3 categorías.
Resultado esperado para el ejemplo proporcionado: ALEMANIA (6 medallas)*/
struct PAIS {
		char NOMBRE[30];
		int ORO;
		int PLATA;
		int BRONCE;
};
struct ATLETA {
		char NOMBRE[50];
		char PAIS[30];
		int ORO;
		int PLATA;
		int BRONCE;
};
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	FILE * FPPAISES,*FPATLETAS,*FPPAISESTXT;
	struct PAIS P;
	struct ATLETA A;
	int TAMANO=0;
	int I;
	int ORO=0;
	int PLATA=0;
	int BRONCE=0;
	//--------------------------------------------------------------------PUNTO 1------------------------------------------------------------------------------
	if((FPPAISES=fopen("PAISES","rb"))==NULL){
		printf("\nError al abrir el archivo");
		exit(1);
	}
	if((FPATLETAS=fopen("ATLETAS","rb"))==NULL){
		printf("\nError al abrir el archivo");
		exit(1);
	}
	//ARCHIVO ATLETAS
	fseek(FPATLETAS,0L,SEEK_END);
	TAMANO=ftell(FPATLETAS)/sizeof(A);
	fseek(FPATLETAS,0L,SEEK_SET);
	printf("\n TAMAÑO DEL ARCHIVO ATLETAS: %d REGISTROS: \n\n", TAMANO);
	
	printf("\n %-15s \t %-15s \t %-15s %-15s  %-15s \n","NOMBRE","PAIS","ORO","PLATA","BRONCE" );
	for(I=0;I<TAMANO;I++){
	fread(&A,sizeof(A),1,FPATLETAS);
	printf("\n %-15s \t %-15s \t %d \t\t %d \t\t %d \n",A.NOMBRE,A.PAIS,A.ORO,A.PLATA,A.BRONCE);	
	}
	int TAMANOPAISES=0;
	//ARCHIVO PAISES
	fseek(FPPAISES,0L,SEEK_END);
	TAMANOPAISES=ftell(FPPAISES)/sizeof(P);
	fseek(FPPAISES,0L,SEEK_SET);
	printf("\n TAMAÑO DEL ARCHIVO PAISES: %d REGISTROS: \n\n", TAMANOPAISES);
	
	printf("\n %-15s \t %-15s %-15s  %-15s \n","NOMBRE","PAIS","ORO","PLATA","BRONCE" );
	for(I=0;I<TAMANOPAISES;I++){
	fread(&P,sizeof(P),1,FPPAISES);
	printf("\n %-15s \t %d \t\t %d \t\t %d \n",P.NOMBRE,P.ORO,P.PLATA,P.BRONCE);	
	}
	
	fclose (FPPAISES);
	fclose (FPATLETAS);
	printf("\nCIERRO ARCHIVOS Y VUELVO A ABRIR");
	//--------------------------------------------------------------------PUNTO 2------------------------------------------------------------------------------
	
	if((FPPAISES=fopen("PAISES","r+b"))==NULL){
		printf("\nError al abrir el archivo");
		exit(1);
	}
	if((FPATLETAS=fopen("ATLETAS","rb"))==NULL){
		printf("\nError al abrir el archivo");
		exit(1);
	}
		printf("\nCIERRO ARCHIVOS Y VUELVO A ABRIR");
	
	
	fread(&P,sizeof(P),1,FPPAISES);
	
	while(!feof(FPPAISES)){
		printf("\n PAIS DE PAISES %-15s",P.NOMBRE);
		fseek(FPATLETAS,0L,SEEK_SET);
						fread(&A,sizeof(A),1,FPATLETAS);
							while(!feof(FPATLETAS))
							{	printf("\n PAIS DE ATLETAS %-15s",A.PAIS);
							
								if(!stricmp(A.PAIS,P.NOMBRE))
								{
									printf("\nIGUALDAD DE PAISES");
									getchar();
									P.ORO=P.ORO+A.ORO;
									P.PLATA=P.PLATA+A.PLATA;
									P.BRONCE=P.BRONCE+A.BRONCE;
									strcpy(A.PAIS,P.NOMBRE);
									fseek(FPPAISES,-1*sizeof(P),SEEK_CUR);
									fwrite(&P,sizeof(P),1,FPPAISES);
									fseek(FPPAISES,0L,SEEK_CUR);
									
								}
									
									fread(&A,sizeof(A),1,FPATLETAS);	
							}
			
			fread(&P,sizeof(P),1,FPPAISES);
			
	}
	
		fclose (FPPAISES);
		fclose (FPATLETAS);
			//--------------------------------------------------------------------PUNTO 2------------------------------------------------------------------------------
		int GANADORCANTIDAD=0;
		char GANADORPAIS[20];
		int CONTADORMEDALLAS2=0;
		char CAR;
		
		if((FPPAISES=fopen("PAISES","rb"))==NULL){
		printf("\nError al abrir el archivo");
		exit(1);}
		
	for(I=0;I<TAMANOPAISES;I++){
	fread(&P,sizeof(P),1,FPPAISES);
	
	if(GANADORCANTIDAD< (P.ORO+P.PLATA+P.BRONCE)){
		GANADORCANTIDAD=P.ORO+P.PLATA+P.BRONCE;
		strcpy(GANADORPAIS,P.NOMBRE);
	}
		printf("\n %-15s \t %d \t\t %d \t\t %d \n",P.NOMBRE,P.ORO,P.PLATA,P.BRONCE);	
	}
	
	
	
		printf("\n El PAIS QUE MAS MEDALLAS OBTUVO ES %s CON UN TOTAL DE %d MEDALLAS GANADAS. ",GANADORPAIS,GANADORCANTIDAD);	
	
		fclose (FPPAISES);
		
		//---------------------------------------------------------------------------------------------------------------------------
			if((FPPAISES=fopen("PAISES","rb"))==NULL){
		printf("\nError al abrir el archivo");
		exit(1);}
		
			if((FPPAISESTXT=fopen("PAISES.txt","w"))==NULL){
		printf("\nError al abrir el archivo");
		exit(1);}
		
			
		fread(&P,sizeof(P),1,FPPAISES);
		//CAR=getc(FPPAISES);
		
		while(!feof(FPPAISES)){
			
			fprintf(FPPAISESTXT," %s \t %d \t %d \t %d ",  P.NOMBRE,P.ORO,P.PLATA,P.BRONCE );
			
			fprintf(FPPAISESTXT,"\n");
			
			fread(&P,sizeof(P),1,FPPAISES);
			//putc(CAR,FPPAISESTXT);
			//CAR=getc(FPPAISES);
		
		}
	
			fclose (FPPAISES);
			fclose (FPPAISESTXT);
			
	
		
		
		
	return 0;
}


