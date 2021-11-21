#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct VENTAS {
	char nombre[20];
   	int ventas;
   	int codigo_pais;
};

struct PAISES {
	char pais[20];
   	int codigo_pais;
};
   

   int verficarPais(FILE * FPDATOS, char pais[]) {
     	struct PAISES pa;
	    FILE * FP;
	    int j, N;
	    
	     // -- CANTIDAD DE REGISTROS 
	    fseek(FPDATOS, 0, SEEK_END);
        N = ftell(FPDATOS)/ sizeof(pa);
	    
	    rewind(FPDATOS);
      
		for (j=0; j<=N; j++) {
		
    	  if(strcmp(pa.pais, pais) == 0){
    	  	return pa.codigo_pais;
    	  }
		  
		  fread(&pa, sizeof(pa), 1, FPDATOS);	  
    }
	 return -1;
}






// -------------------------------------------------------------- Ejercicio 2 -------------------------------------------------------------- 
    void EJERCICIO_2 () {
      FILE * FP;
      FILE * FV;
      
 	  struct VENTAS vent;
 	  struct PAISES pa;
 	  
	   if ((FV = fopen("VENTAS", "r+b")) == NULL) {
 		 printf("Error al abrir el archivo VENTAS");
	     exit(1);
	  }
	   if ((FP = fopen("PAISES", "r+b")) == NULL) {
 		 printf("Error al abrir el archivo PAISES");
	     exit(1);
	  }
	
	printf("\n\n -------------------------------  VENTAS -------------------------------");
	
	printf("\n\n\t  %-20s %20s %20s","CANTIDAD VENTAS", "NOMBRE", "CODIGO" );
	
    fread(&vent, sizeof(vent), 1, FV);
    

	while(!feof(FV)){
		printf("\n\n\n\t\t %10d %20s \t  %10d",
     	 vent.ventas ,vent.nombre, vent.codigo_pais );
		
		fread(&vent, sizeof(vent), 1, FV);
	}
	
	printf("\n\n");	
	
    fclose(FV);
    
    
    printf("\n\n -------------------------------  PAISES -------------------------------");



   	printf("\n\n\t  %-20s %20s ","CODIGO", "PAIS" );	
    fread(&pa, sizeof(pa), 1, FP);
	
	while (!feof(FP)) {
			printf("\n\n\n\t\t %10d %20s",
     	 pa.codigo_pais, pa.pais );
		
		fread(&pa, sizeof(pa), 1, FP);
	}
		
    fclose(FP);

}
   
   
   
//  -------------------------------------------------------------- Ejercicio 1 --------------------------------------------------------------
  void EJERCICIO_1() {
  	  FILE * FV;
  	  FILE * FP;
 	  struct VENTAS vent;
 	  struct PAISES pa;
 	  int codigo_pais;
 	  int cont_pais_buscado = 0;
 	  int cont_asignacion = 1;
 	  int i;
 	  int value;
 	  

	if ((FP = fopen("PAISES", "a+")) == NULL) {
 		printf("Error al crear el archivo PAISES");
	    exit(1);
	 }
	 
	if((FV = fopen("VENTAS", "a+")) == NULL){
 	  printf("Error al crear el archivo VENTAS");
	  exit(1);
}
	
	printf("\n\n\n\t\t ----------- BIENVENIDO AL SISTEMA DE CARGA DE VENDEDORES -----------");
	
	printf("\n\n");
	
	while(vent.ventas != -1) {
		    
	    fflush(stdin);
		
		printf("\nIngrese la cantidad de ventas: ");
	    scanf("%d", &vent.ventas);
		if(vent.ventas == -1) exit(1);
		
	    fflush(stdin);
		
		printf("\nIngrese el nombre del vendedor: ");
	    gets(vent.nombre);
	    
	    fflush(stdin);
		
		printf("\nIngrese pais: ");
     	gets(pa.pais);
     	
     	fflush(stdin);
	            
     	cont_pais_buscado = verficarPais(FP, pa.pais);
        
        if(cont_pais_buscado >= 0){
            if(cont_pais_buscado == 0) pa.codigo_pais = cont_pais_buscado + 1;
        	pa.codigo_pais = cont_pais_buscado;
        	vent.codigo_pais = cont_pais_buscado;
        } else {
        	pa.codigo_pais = cont_asignacion;
        	vent.codigo_pais = cont_asignacion;
        	cont_asignacion++;
        	
        }
     	
     	fwrite(&pa, sizeof(pa), 1, FP);    
		fwrite(&vent, sizeof(vent), 1, FV);
    
	}

    fclose(FV);
    fclose(FP);
    
}   

   int main () {
 
   //EJERCICIO_1();
   EJERCICIO_2();


	 return 0;
  } 
