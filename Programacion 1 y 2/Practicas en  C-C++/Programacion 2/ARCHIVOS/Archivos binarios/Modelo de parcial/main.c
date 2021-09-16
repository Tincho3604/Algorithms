
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   struct VENTAS {
	    char nombre[20];
   	    int ventas;
   	    char pais[20];
   };
   
   int main () {
 	FILE * FV;
 	FILE * FP;
 	struct VENTAS vent;
 	int codigo_pais;


	// Ejercicio 1
 	if((FV = fopen("VENTAS", "a+")) == NULL){
 		printf("Error al crear el archivo");
	    exit(1);
	 }
	 
	if((FP = fopen("PAISES", "a+")) == NULL){
 		printf("Error al crear el archivo");
	    exit(1);
	 }
	
	while(vent.ventas != -1) {
		
	    fflush(stdin);
	    
	    
		printf("\nIngrese el nombre del vendedor: ");
	    gets(vent.nombre);
	    
	    fflush(stdin);
	    
	    printf("\nIngrese la cantidad de ventas: ");
	    scanf("%d", &vent.ventas);
	    
	    fwrite(&vent, sizeof(vent), 1, FV);
	    
	      fflush(stdin);
	    
	    printf("\nIngrese el pais: ");
	    gets(vent.pais);
		fwrite(&vent, sizeof(vent), 1, FP);
	}

    fclose(FP);






    // Ejercicio 2

 	if((FP = fopen("VENTAS", "r+b")) == NULL){
 		printf("Error al crear el archivo");
	    exit(1);
	 }
	
	printf("\n\n\n\t\t %20s  %20s %20s","CANTIDAD VENTAS", "NOMBRE", "PAIS");
	
    fread(&vent, sizeof(vent), 1, FP);
    
	while(!feof(FP)){
		printf("\n\n\n\t\t%10d %20s %20s",
     	vent.ventas	,vent.nombre, vent.pais );
		
		fread(&vent, sizeof(vent), 1, FP);
	}
	
	printf("\n\n");	
	
	
    fclose(FP);
	 return 0;
  } 
