#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct PRODUCTO {
		int codigo;
		char descripccion[40];
		float precio;
};

//CONTINUAR.
void continuar(){
	printf("\n\nPresione una tecla para continuar");
	getch();
}









//CREACION DE ARCHIVO  1 - Crear un archivo llamado \"productos.dat\".
void crear(){
	FILE * arch;
	if((arch= fopen("productos","wb")) == NULL){
		printf("Error al acceder a archivo");
		exit(1);
	}
	fclose(arch);
	continuar();
}











//CARGAR PRODUCTO.   2 - Carda de registros del producto.
void cargar(){
	struct PRODUCTO prod;

	char D;
	bool flag = true;
	
	FILE * arch;
	
	if((arch= fopen("productos", "ab")) == NULL){
		printf("Error al acceder al archivo");
		exit(1);
	}

while(flag){
	printf("\n\n");
	printf("Ingrese el codigo del producto: ");
	scanf("%d", &prod.codigo);
	
	fflush(stdin);
	
	printf("Ingrese la descripccion del producto: ");
	gets(prod.descripccion);
	
	fflush(stdin);
	printf("Ingrese el precio: ");
	scanf("%f", &prod.precio);
	
	fwrite(&prod, sizeof(prod), 1, arch);
	
	fflush(stdin);
	printf("Desea seguir agregando productos a la Base de datos S/N: ");
	D = getchar();
	
 	
    
	if(D == 'N'){
		flag = false;
	}
	
};
    printf("\n\n");
	fclose(arch);
	continuar();
}










// MOSTRAR LISTADO  3 - Listado completo de productos.
void listado(){
	FILE * arch;
	struct PRODUCTO prod;
	
	if((arch = fopen("productos", "rb")) == NULL){
		printf("Error al acceder al archivo");
		exit(1);
	}
	
	fread(&prod, sizeof(prod), 1, arch);
	    printf("\n\n\t\t%-20s %10s \t%10s","CODIGO", "DESCRIPCCION", "PRECIO");
	        while(!feof(arch)){
	      	    printf("\n\n\t%10d \t\t%10s \t\t%10f",
				prod.codigo,prod.descripccion,prod.precio);
		    fread(&prod, sizeof(prod), 1, arch);
		  }
		printf("\n\n");	
		  
		fclose(arch);
}







// MODIFICAR EL PRODUCTO 4 - Consulta de un producto por su codigo.
void consulta(){
	FILE * arch;
	struct PRODUCTO prod;
	int cod;
	int existe = 0;
	if((arch = fopen("productos", "rb")) == NULL){
		printf("Error al acceder al archivo");
		exit(1);
	}
	
	printf("\nIngrese el codigo del producto: ");
	scanf("%d",&cod);
	
	   fread(&prod, sizeof(prod), 1, arch);
	   printf("\n\n\t\t%-20s %10s \t%10s","CODIGO", "DESCRIPCCION", "PRECIO");
	
	while(!feof(arch)){
		if(cod == prod.codigo){
		
		printf("\n\n\t%10d \t\t%10s \t\t%10f",
		prod.codigo,prod.descripccion,prod.precio);
		existe = 1;
	}
		fread(&prod, sizeof(prod), 1 , arch);
	
	}
	fclose(arch);
	
	if(existe == 0){
	   printf("\nEl articulo no existe");	
	}
	continuar();	
}










// MODIFICAR PRODUCTO 5 - Modificacion del precio de un producto."
void modificar(){
	FILE * arch;
	struct PRODUCTO prod;
    int cod, POS, existe = 0, N;
    bool flag = true;
    char D;
    
    if((arch = fopen("productos", "r+b")) == NULL){
    	printf("Error al acceder al archivo");
		exit(1);
	}
    
    printf("\n\nIngrese el producto a modificar:  ");
    scanf("%d",&cod);


    fread(&prod, sizeof(prod), 1, arch);
    while(!feof(arch) && flag){
    	if(cod == prod.codigo){
        
        printf("\nEl producto que elegiste es: ");
		printf("\n\n\t%10d \t\t%10s \t\t%10f",
		prod.codigo,prod.descripccion,prod.precio);
		
		printf("\nIngrese el nuevo codigo: ");
		scanf("%d", &prod.codigo);
		
		fflush(stdin);
		printf("\nIngrese nueva descripccion: ");
		gets(prod.descripccion);
		
		fflush(stdin);
		printf("\nIngrese el nuevo precio: ");
		scanf("%f", &prod.precio);
		
		fseek(arch, (-1)*sizeof(prod), SEEK_CUR);
		
		fwrite(&prod, sizeof(prod), 1, arch);
		
		existe = 1;
		printf("\n\n ¡EL PRODUCTO SE HA MODIFICADO EXITOSAMENTE! ");
		}
		
		fread(&prod, sizeof(prod), 1, arch);
		
		
		fflush(stdin);
	    printf("\n¿Desea seguir modificando productos en la Base de datos S/N? : ");
	    D = getchar();


	    if(D == 'N'){
	    	flag = false;
	    }
    }

	   if(existe == 0){
	        printf("\nEl articulo no existe");	
	    }

	
    printf("\n\n");
	fclose(arch);
	continuar();
}










// BORRAR PRODUCTO 6 - Borrar articulo de la BD
void borrar(){
	FILE * arch, * archTemp;
	struct PRODUCTO prod;
    bool flag = true;
    char opccionBorrar;
	int cod;
	
		
	
	if((arch = fopen("productos", "r+b")) == NULL){
		printf("\nError al acceder al archivo");
		exit(1);
	}
	
	
	if((archTemp = tmpfile()) == NULL){
		printf("Error al acceder al archivo temporal");
		exit(1);
	}
	
	
	printf("\n\n");
	printf("\nIntroduzca el codigo del producto a borrar: ");
	scanf("%d", &cod);
	
	fread(&prod, sizeof(prod), 1, arch);
	while(!feof(arch)){
		printf("dato");
		if(cod != prod.codigo){
			fwrite(&prod, sizeof(prod), 1, archTemp);
	}
	fread(&prod, sizeof(prod), 1, arch);
  }
  
  fclose(arch);
  
  
  	if((arch = fopen("productos", "wb")) == NULL){
		printf("\nError al acceder al archivo");
		exit(1);
	}
  

    rewind(archTemp);

  	fread(&prod, sizeof(prod), 1, archTemp);
	while(!feof(archTemp)){
			fwrite(&prod, sizeof(prod), 1, arch);
			fread(&prod, sizeof(prod), 1, archTemp);
  }
    fclose(arch);
    fclose(archTemp);
    
    printf("\nEl archivo se borro exitosamente: ");
    
	continuar();
}





int main(){
    int opccion;
    do{
    printf("\n\n");
    printf("1 - Crear un archivo llamado \"productos.dat\"\n");
    printf("2 - Carga de registros del producto. \n");
    printf("3 - Listado completo de productos. \n");
    printf("4 - Consulta de un producto por su codigo. \n");
    printf("5 - Modificacion del precio de un producto. \n");
    printf("6 - Borrar articulo de la BD \n");
    printf("7 - Finalizar tarea. \n");
    printf("\n");
    printf("Ingrese su opccion: ");
    scanf("%d", &opccion);
    
    switch(opccion) {
    	case 1: crear();
    		break;
        case 2:
        	   cargar();
    		break;
        case 3:
        	   listado();
    		break;
    	case 4:
    		   consulta();
    		break;
    	case 5:
    		  modificar();
    		break;
    	case 6:
    		  borrar();
    		break;
    		
    	default:
    		printf("\nOpccion incorrecta");
    		break;
	}
}while(opccion != 7);
    
    return 0;
}

