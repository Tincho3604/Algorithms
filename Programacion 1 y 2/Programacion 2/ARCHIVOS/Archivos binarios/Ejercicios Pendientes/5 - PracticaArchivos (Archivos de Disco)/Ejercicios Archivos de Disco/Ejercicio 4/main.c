   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct NEGOCIO {
	int numero_articulo;
	char descripccion[30];
	float precio;
	char proveedor[30];
	int stock;
};


struct NOVEDADES {
	char proveedor[30];
	int porcentaje;
};





void crearNovedades(){
	FILE * FP; 
	struct NOVEDADES novedades;
	char opccion;
	
	if ((FP = fopen("novedades.dat", "a+")) == NULL) {
		printf("Error al crear el archivo novedades.dat");
		exit(1);
	}
	
	fread(&novedades, sizeof(novedades), 1, FP);
	  while (opccion != 'N') {
		
		fflush(stdin);
		
		printf("\n\n Ingrese proveedor: ");
		gets(novedades.proveedor);
		
		fflush(stdin);
		
		printf("\n\n Ingrese porcentaje: ");
		scanf("%d", &novedades.porcentaje);
		

		fwrite(&novedades, sizeof(novedades), 1, FP);
		
		fflush(stdin);
		
		printf("\n\n\n Desea seguir ingresando noveades S/N: ");
		opccion = getchar();
	}
	
	fclose(FP);
}





int verificarNovedades(char proveedorBuscado[]) {
	FILE * FPNOVE;
	struct NOVEDADES novedades;
	
	if ((FPNOVE = fopen("novedades.dat", "r+b")) == NULL) {
		printf("Error al abrir el archivo novedades.dat");
		exit(1);
	}
	
	fread(&novedades, sizeof(novedades), 1, FPNOVE);
	
	while (!feof(FPNOVE)) {
	  if(strcmp(proveedorBuscado, novedades.proveedor) == 0){
		   return novedades.porcentaje;
	 }
 		fread(&novedades, sizeof(novedades), 1, FPNOVE);
	}
	
	return -1;
	fclose(FPNOVE);
}





void actualizarDat() {

	FILE * FPNEGOCIO; 
	struct NEGOCIO negocio;
	float valorAumento = 0.00;
	
	if ((FPNEGOCIO = fopen("lista.dat", "r+b")) == NULL) {
		printf("Error al abrir el archivo list.dat");
		exit(1);
	}
	
	fread(&negocio, sizeof(negocio), 1, FPNEGOCIO);
	   while(!feof(FPNEGOCIO)) {
		if (verificarNovedades(negocio.proveedor) > 0) {
			
		   valorAumento = (negocio.precio * verificarNovedades(negocio.proveedor)) / 100;
		   negocio.precio += valorAumento;
			
		   fseek(FPNEGOCIO, (long)(-1)*sizeof(negocio), SEEK_CUR);
		   fwrite(&negocio, sizeof(negocio), 1, FPNEGOCIO);
		   fseek(FPNEGOCIO, 0L, SEEK_CUR);
		   
		   valorAumento = 0.00;
		} 
		
		fread(&negocio, sizeof(negocio), 1, FPNEGOCIO);
	}
	
	fclose(FPNEGOCIO);
	
	printf("\n\n Se actualizo list.dat de manera exitosa");
}




void leer(){
	struct NEGOCIO negocio;
    FILE * FP;

	if((FP = fopen("lista.dat", "r+b")) == NULL){
		printf("Error al crear el archivo lista.dat");
		exit(1);
	}
	
	printf("\n\n\t\t%-20s %20s %20s %20s %20s","NUMERO ARTICULO", "DESCRIPCCION", "PRECIO", "PROVEEDOR", "STOCK");
	fread(&negocio, sizeof(negocio), 1, FP);
	  
	  while (!feof(FP)) {
		printf("\n\n\n\t \t%10d \t%20s\t \t%10f \t%20s\t \t%10d",
		negocio.numero_articulo, negocio.descripccion, negocio.precio, negocio.proveedor, negocio.stock);

		fread(&negocio, sizeof(negocio), 1, FP);
	}
	
	fclose(FP);
}



int main () {
    
	//crearNovedades(); 
    //actualizarDat();
    leer();
	return 0;
}
