/*  

EL ARCHIVO BDPEREZ ESTA COMPUESTO POR REGISTROS DE LA FORMA struct ARTICULO.

EL PROVEEDOR PEREZ SOLO COMERCIALIZA UN ARTICULO  

SE REQUIERE DEPURAR LA BD DE FORMA DE ELIMINAR TODOS LOS ARTICULOS 
DE LOS PROVEEDORES QUE COMERCIALICEN EL MISMO ARTICULO DE PEREZ

ES DECIR, BORRAR DEL MAPA A LA COMPETENCIA EN TODOS SUS ARTICULOS

TENER CUIDADO DE NO ELIMINAR A PEREZ

INDICAR CUANTOS REGISTROS QUEDARON

*/

            

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct ARTICULO {
	int NUMART ;
	char DESCRIP[20];
	int STOCK ;
	char PROVE[15] ;
	float COSTO ;
};


void leerPerez() {
	FILE * FPEREZ;
	struct ARTICULO art;
	int N;
	
	
	if ((FPEREZ = fopen("BDPEREZ", "r+b")) == NULL) {
		printf("Error al querer abrir el archivo PEREZ");
		exit(1);
	}
	
	printf("\n\n\n\t\t %-20s %-20s %-20s %-20s %-20s ", "NUMART", "DESCRIP", "STOCK", "PROVE", "COSTO");
   
   
	// -- CANTIDAD DE REGISTROS 
	fseek(FPEREZ, 0, SEEK_END);
    N = ftell(FPEREZ)/ sizeof(art);
    
    
    printf("\n Quedaron : %d Registros",N);
    
    
    	    
	rewind(FPEREZ);
	
	
	fread(&art, sizeof(art), 1, FPEREZ);
	    while(!feof(FPEREZ)) {
		    printf("\n\n\n\t\t %10d %20s \t%10d \t%10s \t%10f", 
		        art.NUMART, art.DESCRIP, art.STOCK, art.PROVE, art.COSTO);
				fread(&art, sizeof(art), 1, FPEREZ);
	}	
	
	fclose(FPEREZ);
}



void eliminarCompetencia(char producto[], int codigo_perez){
		FILE * FPEREZ;
		FILE * FPAUX;
	   struct ARTICULO art;
	
	if ((FPEREZ = fopen("BDPEREZ", "rb")) == NULL) {
		printf("Error al querer abrir el archivo PEREZ");
		exit(1);
	}
	
		if ((FPAUX = fopen("BDAUX", "wb")) == NULL) {
		printf("Error al querer abrir el archivo PEREZ");
		exit(1);
	}
	
	fread(&art, sizeof(art), 1, FPEREZ);
	    while(!feof(FPEREZ)) {
	    	                      

	    	if ((strcmp(art.DESCRIP, producto) != 0) || (art.NUMART == codigo_perez)) 
				fwrite(&art, sizeof(art), 1, FPAUX);
		   fread(&art, sizeof(art), 1, FPEREZ);
	   }
	
	fclose(FPEREZ);
	fclose(FPAUX);
	
	remove("BDPEREZ");
	rename("BDAUX", "BDPEREZ");
	
	printf("\n\n\n OPERACION ELIMINAR COMPETENCIA COMPLETA EXITOSAMENTE!!!");
}


void main(){
    
	    leerPerez();
	
	 	/*    
	FILE * FPEREZ;
	struct ARTICULO art;
	char productoBuscado[1][20];
	int codigo_art_perez;
	
	if ((FPEREZ = fopen("BDPEREZ", "r+b")) == NULL) {
		printf("Error al querer abrir el archivo PEREZ");
		exit(1);
	}
	

	fread(&art, sizeof(art), 1, FPEREZ);
	    while(!feof(FPEREZ)) {
	    	if (strcmp(art.PROVE, "PEREZ") == 0) {
		        strcpy(productoBuscado, art.DESCRIP);
		        codigo_art_perez = art.NUMART;
		        
		        fread(&art, sizeof(art), 1, FPEREZ);
	    }
		fread(&art, sizeof(art), 1, FPEREZ);
	}
	
	fclose(FPEREZ);
	
	eliminarCompetencia(productoBuscado, codigo_art_perez);
*/

}

