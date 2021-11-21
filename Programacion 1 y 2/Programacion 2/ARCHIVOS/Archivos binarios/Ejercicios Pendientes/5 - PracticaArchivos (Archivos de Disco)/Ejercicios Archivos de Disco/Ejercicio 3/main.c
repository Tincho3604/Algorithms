   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

struct NEGOCIO {
	int numero_articulo;
	char descripccion[30];
	float precio;
	char proveedor[30];
	int stock;
};


void crearArchivo(){
    struct NEGOCIO negocio;
    FILE * FP;
	char opccion;
	
	if((FP = fopen("lista.dat", "a+")) == NULL){
		printf("Error al crear el archivo lista.dat");
		exit(1);
	}
	
	printf("\n\n Bienvenido al sistema de carga de list.dat");
	fread(&negocio, sizeof(negocio), 1, FP);
	  while(opccion != 'N'){
	  	
		fflush(stdin);
	  	
	  	printf("\n\nIngrese el numero de articulo: ");
	    scanf("%d", &negocio.numero_articulo);
	    
	    fflush(stdin);
	    
	    printf("\n\n Ingrese descripccion: ");
	    gets(negocio.descripccion);
	  
	    fflush(stdin);
	  
	    printf("\n\n Ingrese precio: ");
	    scanf("%f", &negocio.precio);
	    
	    fflush(stdin);
	    
	    printf("\n\n Ingrese proveedor: ");
	    gets(negocio.proveedor);
	    
	    fflush(stdin);
	    
	    printf("\n\n Ingrese el stock: ");
	    scanf("%d", &negocio.stock);
	  
	  
	    fwrite(&negocio, sizeof(negocio), 1, FP);
	  
	    fflush(stdin);
	  
	    printf("\n\n Desea seguir cargando articulos en la base de datos S/N:   ");
	    opccion = getchar();
	    
	  }	
	  
	  fclose(FP);
	  printf("\n Archivo creado exitosamente!" );
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
	  while(!feof(FP)){
		printf("\n\n\n\t \t%10d \t%20s\t \t%10f \t%20s\t \t%10d",
		negocio.numero_articulo, negocio.descripccion, negocio.precio, negocio.proveedor, negocio.stock);

		fread(&negocio, sizeof(negocio), 1, FP);
	}
	
	fclose(FP);
}


void aumentoPerez() {
	struct NEGOCIO negocio;
    FILE * FP;
    float valor_aumento = 0;
    if((FP = fopen("lista.dat", "r+b")) == NULL){
		printf("Error al crear el archivo lista.dat");
		exit(1);
	}
	
	fread(&negocio, sizeof(negocio), 1, FP);
	  while (!feof(FP)) {
		if(strcmp(negocio.proveedor, "PEREZ") == 0 ){
			
           valor_aumento = (negocio.precio * 20) / 100;
           negocio.precio += valor_aumento;
           
           fseek(FP, (long)(-1)*sizeof(negocio), SEEK_CUR);
		   fwrite(&negocio, sizeof(negocio), 1, FP);
		   fseek(FP, 0L, SEEK_CUR);
		   
		   valor_aumento = 0;
	   }
	   	fread(&negocio, sizeof(negocio), 1, FP);
	}
	
	fclose(FP);
	printf("\n\n Aumento completado satisfactoriamente");
}

int main(){
	//crearArchivo();
    //aumentoPerez();
	leer();
}
