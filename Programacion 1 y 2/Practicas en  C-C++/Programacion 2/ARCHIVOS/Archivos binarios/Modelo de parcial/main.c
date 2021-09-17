
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct VENTAS {
	char nombre[20];
   	int ventas;
   	char pais[20];
   	int codigo_pais;
};
   

   int buscarPais(char arrPais[], char pais){
   	int j;
	for(j=0; j<3; j++) {
      if(strcmp(arrPais[j], pais) == 0){
      	 return j;
      } 
   }
    return -1;	
}



// -------------------------------------------------------------- Ejercicio 2 -------------------------------------------------------------- 
    void EJERCICIO_2 () {
      FILE * FP;
      FILE * FV;
      
 	  struct VENTAS vent;
 	  
	   if ((FV = fopen("VENTAS", "r+b")) == NULL) {
 		 printf("Error al abrir el archivo");
	     exit(1);
	  }
	   if ((FP = fopen("PAISES", "r+b")) == NULL) {
 		 printf("Error al abrir el archivo");
	     exit(1);
	  }
	
	printf("\n\n -------------------------------  VENTAS -------------------------------");
	
	printf("\n\n\n\t\t %20s  %20s %20s","CODIGO" "CANTIDAD VENTAS", "NOMBRE");
	
    fread(&vent, sizeof(vent), 1, FV);
    

	while(!feof(FV)){
		printf("\n\n\n\t\%10d %20s %10d",
     	 vent.ventas ,vent.nombre, vent.codigo_pais );
		
		fread(&vent, sizeof(vent), 1, FV);
	}
	
	printf("\n\n");	
	
    fclose(FV);
    
    
    
    printf("\n\n -------------------------------  PAISES -------------------------------");
    
    printf("\n\n\n\t\t %20S %20s","CODIGO" "PAISES");
	
    fread(&vent, sizeof(vent), 1, FP);
    
	while(!feof(FP)){
		printf("\n\n\n\t\t %10d %20s",
        vent.codigo_pais ,vent.pais);
		
		fread(&vent, sizeof(vent), 1, FP);
	}
		
    fclose(FP);

}
   
   
   
//  -------------------------------------------------------------- Ejercicio 1 --------------------------------------------------------------
  void EJERCICIO_1() {
  	  FILE * FV;
  	  FILE * FP;
 	  struct VENTAS vent;
 	  int codigo_pais;
 	  char array_Paises[3][30]; 
 	  int cont_paises = 0;
 	  int value = 0;
 	  int i;
 	  
	if((FV = fopen("VENTAS", "a+")) == NULL){
 		printf("Error al crear el archivo");
	    exit(1);
	 }
	 
	if((FP = fopen("PAISES", "a+")) == NULL){
 		printf("Error al crear el archivo");
	    exit(1);
	 }
	
	printf("\n\n\n\t\t ----------- BIENVENIDO AL SISTEMA DE CARGA DE VENDEDORES -----------");
	
	
	while(vent.ventas != -1) {
		
	    printf("\nIngrese pais: ");
     	gets(vent.pais);
     	
        
        cont_paises++;
        
     //   value = buscarPais(array_Paises, vent.pais);
        
        if(value < 0) {
        	strcpy(array_Paises[cont_paises],vent.pais);
        } else {
		       vent.codigo_pais = cont_paises;
		}
    	
		fwrite(&vent, sizeof(vent), 1, FP);
	    fflush(stdin);
	    
		printf("\nIngrese el nombre del vendedor: ");
	    gets(vent.nombre);
	    
	    fflush(stdin);
	    
	    printf("\nIngrese la cantidad de ventas: ");
	    scanf("%d", &vent.ventas);
	    
		fflush(stdin);
		
	    fwrite(&vent, sizeof(vent), 1, FV);
	    
	}

    fclose(FV);
    fclose(FP);
    
}   
   
   int main () {
 
   EJERCICIO_1();
   //EJERCICIO_2();


	 return 0;
  } 
