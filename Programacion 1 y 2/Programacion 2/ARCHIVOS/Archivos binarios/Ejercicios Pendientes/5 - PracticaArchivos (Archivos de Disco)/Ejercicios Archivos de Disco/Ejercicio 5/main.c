   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
5) Dado el mismo archivo con artículos lista.dat, mostrar en pantalla y almacenar en un 
archivo la “nota de pedido” para completar el stock mínimo de artículos. El stock mínimo de 
cada artículo está almacenado en un archivo llamado SM.dat estructurado como nº de 
artículo (int) y cantidad mínima (int). Se pide armar una lista de productos que son 
necesarios reponer y cuántos deben comprarse de cada uno (como mínimo) para alcanzar 
el nivel de stock mínimo. El archivo con la nota de pedido debe poder abrirse con un editor 
de texto normal.
*/

struct NEGOCIO {
	int numero_articulo;
	char descripccion[30];
	float precio;
	char proveedor[30];
	int stock;
};

struct STOCK_MINIMO {
	int numero_articulo;
	int cantidad_minima;
};




void crear_stock_minimo() {
	struct STOCK_MINIMO stockMin;
	struct NEGOCIO negocio;
	FILE * STOCK;
	FILE * FPNEGOCIO;
	int N, i = 0;
	
	
	if ((FPNEGOCIO = fopen("lista.dat", "r+b")) == NULL) {
		printf("Error al crear el archivo lista.dat");
		exit(1);
	}
	

	// -- CANTIDAD DE REGISTROS 
	fseek(FPNEGOCIO, 0, SEEK_END);
    N = ftell(FPNEGOCIO)/ sizeof(negocio);
	
	rewind(FPNEGOCIO);
	
	

	if((STOCK = fopen("SM.dat", "a+")) == NULL){
		printf("Error al crear el archivo SM.dat");
		exit(1);
	}
	
	
	
	fread(&negocio, sizeof(negocio), 1, FPNEGOCIO);
	fread(&stockMin, sizeof(stockMin), 1, STOCK);
	for(i = 0; i<N; i++) {
		fflush(stdin);
	
		printf("\n\nIngrese el stock minimo del Nro de articulo %d:   ", negocio.numero_articulo);
		scanf("%d",&stockMin.cantidad_minima);
		
        stockMin.numero_articulo = negocio.numero_articulo;
        
        fflush(stdin);
        
	fread(&negocio, sizeof(negocio), 1, FPNEGOCIO);
	fwrite(&stockMin, sizeof(stockMin), 1, STOCK);
	}
	
	
	
	fclose(FPNEGOCIO);
	fclose(STOCK);
	printf("\nCreacion de archivo BD.dat concluida con exito");
}










void leer() {
	struct STOCK_MINIMO stockMin;
    FILE * FP;
    char CAR;
    
	if((FP = fopen("NOTACAMBIO.txt", "r")) == NULL){
		printf("Error al crear el archivo NOTACAMBIO.txt");
		exit(1);
	}
	
	printf("\n\n\t\t%-20s %20s","NUMERO ARTICULO", "STOCK A REPONER");

		CAR = getc(FP);
		while ( CAR != EOF ) {
				putchar ( CAR );
				CAR = getc(FP);
		}
	
	fclose(FP);
}




void crearNotaCambio() {

	struct STOCK_MINIMO stockMin;
	struct NEGOCIO negocio;
    FILE * SM;
    FILE * NOTACAMBIO;
    FILE * LIST;

	if ((SM = fopen("SM.dat", "r+b")) == NULL){
		printf("Error al abrir el archivo SM.dat");
		exit(1);
	}
	
	
	if ((LIST = fopen("lista.dat", "r+b")) == NULL){
		printf("Error al abrir el archivo lista.dat");
		exit(1);
	}
	 
	
	if ((NOTACAMBIO = fopen("NOTACAMBIO.txt", "w")) == NULL){
		printf("Error al crear el archivo NOTACAMBIO.txt");
		exit(1);
	}
	
	
	fread(&stockMin, sizeof(stockMin), 1, SM);
    fread(&negocio, sizeof(negocio), 1, LIST);
    
	fprintf ( NOTACAMBIO , "%20s" , "NUMERO ARTICULO");
	fprintf ( NOTACAMBIO , "%20s" , "STOCK A REPONER");
	fprintf (NOTACAMBIO , "\n" );
	while(!feof(LIST)){
		
		fprintf ( NOTACAMBIO , "\t\t%d" , stockMin.numero_articulo);
		fprintf ( NOTACAMBIO , "\t\t%d" , stockMin.cantidad_minima > negocio.stock ? 
		(stockMin.cantidad_minima - negocio.stock)
		 : 0);
		fprintf (NOTACAMBIO , "\n" );
		
		fread(&stockMin, sizeof(stockMin), 1, SM);
        fread(&negocio, sizeof(negocio), 1, LIST);
	}
	
	fclose(SM);
	fclose(NOTACAMBIO);
	fclose(LIST);
  	printf("\nProceso finalizado exitosamente");
}



int main (){
	//crear_stock_minimo();
	leer();
	//crearNotaCambio();
	
	return 0;
}
