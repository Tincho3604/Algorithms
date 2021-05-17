#include <stdio.h>
#include <stdlib.h>

/*
   1. HACER UN PROGRAMA DE LECTURA. ---> ¡OK!
   2. MOSTRAR LOS ARTICULOS CUYO STOCK ES MENOR QUE 8. --> ¡OK!
   3. DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA. 
   4. PERMITIR EL INGRESO DE UN #ART Y BUSCARLO.
   5. INDEXAR EL ARCHIVO.
   6. ORDENAR EL INDICE.
   7. REPETIR EL PUNTO 4 CON UNA BUSQUEDA BINARIA INDEXADA.
*/




// Estrcutura de la Base de Datos
struct ARTI {
	short int ART;
	char COD[50];
	char DESC[100];
	char FAB[50];
	short int STOCK;
};


//1. HACER UN PROGRAMA DE LECTURA.
void LEER(FILE *FV){
    struct ARTI V;
    
    if((FV=fopen("BDARTICULOS","rb")) == NULL){
    	printf("\n\nError al abrir el archivo");
    	exit(1);
	}
	
	fread(&V, sizeof(V), 1, FV);
	printf("\n\n%20s %20s\t %20s \t%20s %20s\t", 
	"ART", "COD", "DESC", "FAB", "STOCK");
	
	while(!feof(FV)){
		printf("\n\n\n\t%10d %20s\t\t %20s %20s %10d",
		V.ART,V.COD,V.DESC,V.FAB,V.STOCK);
	
		fread(&V, sizeof(V), 1, FV);
	}
	
	printf("\n\n");	
	fclose(FV);
}



//2. MOSTRAR LOS ARTICULOS CUYO STOCK ES MENOR QUE 
void ART_MEN_8(FILE *FV){
    struct ARTI X;
    int N, i, cont = 0;
    
    if((FV=fopen("BDARTICULOS","r+b")) == NULL){
    	printf("\n\nError al abrir el archivo");
    	exit(1);
	}
    
    fseek(FV, 0, SEEK_END);
    N = ftell(FV)/ sizeof(X);
    
    
	rewind(FV);
    fread(&X, sizeof(X), 1 , FV);
	
	printf("\n\n%20s %20s\t %20s \t%20s %20s\t", 
	"ART", "COD", "DESC", "FAB", "STOCK");
	for(i=0; i<N; i++){
    	if(X.STOCK < 8){
    		printf("\n\n\n\t%10d %20s\t\t %20s %20s %10d",
		    X.ART,X.COD,X.DESC,X.FAB,X.STOCK);

    	    fread(&X, sizeof(X), 1, FV);
		}
		 fread(&X, sizeof(X), 1, FV);
	}
	
	fclose(FV);	
}


//3. DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA.

void PROVEEDOR_MAS_ARTICULOS(FILE *FV){
	 struct ARTI X, Y;
	 FILE * TEMP;
	 int i ,j, d, N;
	 int STOCK_MAYOR = 0;
	 int SUM_STOCK = 0;
	 int MAY_STOCK = 0;
	 char MAY_FAB[50];
	 char AUX_FAB[50];
	 char CURRENT_FAB[50];
	 int cont = 0;
	 
	if((FV=fopen("BDARTICULOS","r+b")) == NULL){
    	printf("\n\nError al abrir el archivo");
    	exit(1);
    }
    
    if((TEMP = tmpfile()) == NULL){
    	printf("\nError al acceder a archivo temporal");
    	exit(1);
	}
	
	// -- COPIO A ARCHIVO TEMPORAL
	rewind(FV);
	fread(&X, sizeof(X), 1, FV);
	     while(!feof(FV)){
	       	fwrite(&X, sizeof(X), 1, TEMP);
			fread(&X, sizeof(X), 1, FV);	
		 }
    
	fclose(FV);
	
	// -- CANTIDAD DE REGISTROS 
	fseek(TEMP, 0, SEEK_END);
    N = ftell(TEMP)/ sizeof(X);
	
	rewind(TEMP);
			
	// -- ORDENAR ARCHIVO TEMPORAL
	for(i=0; i<N-1; i++){
		for(j=0; j<N-1-i; j++){
			fread(&X, sizeof(X), 1, TEMP);
			fread(&Y, sizeof(Y), 1, TEMP);
            if((strcmp(X.FAB , Y.FAB)) > 0){
               fseek(TEMP, (-2)*sizeof(X), SEEK_CUR);
               
			   fwrite(&Y, sizeof(Y), 1, TEMP);
               fwrite(&X, sizeof(X), 1, TEMP);
 		    }	
			 fseek(TEMP, (-1)*sizeof(X), SEEK_CUR);	
		}
		rewind(TEMP);
	}
	
    
    fseek(TEMP, 0, SEEK_SET);
    fread(&X, sizeof(X), 1, TEMP);  
    
	SUM_STOCK = X.STOCK;     
	strcpy(CURRENT_FAB, X.FAB);    
	 
    printf("\n\n");
    
    fread(&X, sizeof(X), 1, TEMP);  
	 while(!feof(TEMP)){
  
	   if((strcmp(CURRENT_FAB, X.FAB)) == 0){   
             SUM_STOCK += X.STOCK;
		}else{
	            strcpy(CURRENT_FAB, X.FAB);
	            SUM_STOCK = X.STOCK;
	           
	}
		if(MAY_STOCK < SUM_STOCK){  
		   
			    MAY_STOCK = SUM_STOCK;   
                strcpy(MAY_FAB, CURRENT_FAB);
		}
		
	 fread(&X, sizeof(X), 1, TEMP);
  }  
   
	printf("\n El proveedor con mayor cantidad de articulos es: %10s ", MAY_FAB);
	printf("\n Con la cantidad total de: %10d articulos suministrados ", MAY_STOCK);
    
	fclose(TEMP);
		
}


//3. DETERMINAR QUIEN ES EL PROVEEDOR QUE MAS ARTICULOS SUMINISTRA.







int main(){
	FILE * FP;
    int N;
    int op;
    
    
	do{
	printf("\n\n");
    printf("1 - Leer listado de articulos: \n");
    printf("2 - Leer listado de productos cuyo stock sea menor que 8: \n");
    printf("3 - Leer PROVEEDOR MAS ARTICULOS:  \n");
    printf("\n");
    printf("Ingrese su opccion: ");
    scanf("%d", &op);
     	
    switch(op){
    	case 1: LEER(FP);
    		break;
        case 2:
        	   ART_MEN_8(FP);
    		break;
        case 3:
        	   PROVEEDOR_MAS_ARTICULOS(FP);
    		break;
    	default:
    		printf("\nOpccion incorrecta");
    	break;
	      }
	     
       
 
    }while(op != 4);


 return 0;
}
