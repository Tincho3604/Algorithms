#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


struct ALUMNOS{
	int notas[4];
	int codigo;
	char nombre[20];
	float promedio_alumno;
};


void continuar() { 
	printf("\n\nPresione una tecla para continuar");
	getch();
}

void cambiar_nota(int codigo){
	FILE * FP;
	struct ALUMNOS alum;
	int index_nota;
	int nota_cambio;
	int codigo_busqueda;
		
	if ((FP = fopen("alumnos", "r+b")) == NULL) {
	  printf("Error al abrir el archivo");
	  exit(1);
	}

         while (!feof(FP)) {
         	 if (codigo == alum.codigo) {
    	         
			      printf("\n\n Seleccione el numero de nota que desea cambiar: ");
	              scanf("%d", &index_nota);
	           
			      printf("\n\n Ingrese la nota por la que quiere reemplazar la nota actual: ");
			      scanf("%d", &nota_cambio);

                 alum.notas[index_nota-1] = nota_cambio;
                 
                 fseek(FP, (long)(-1)*sizeof(alum), SEEK_CUR);
				 fwrite(&alum, sizeof(alum), 1, FP);
				 fseek(FP, 0L, SEEK_CUR);
		
			}
		         fread(&alum, sizeof(alum), 1, FP);
		 }
	    
	   fclose(FP);
}




float calcular_promedio(int NOTAS[]) {
   float promedio = 0;
	int i;
   for (i=0; i<4; i++) {
	promedio += NOTAS[i];
  }
  return (promedio / 4);
}



int main () {
	FILE * FP;
	struct ALUMNOS alum, X, Y;
	int OP;
    char ingreso = 'S';
    float promedio;
	int codigo_busqueda;
	bool flag_busqueda = false;
	int N, I, J;
	int x, j;
		   	
	printf("\nElije la opccion que desea seleccionar: ");
    printf("\n\n");
	printf("\n 1- Crear archivo: ");
	printf("\n 2- Cargar datos: ");
	printf("\n 3- Calcular promedio y mostrar promedio: ");
	printf("\n 4- Buscar registro determinado: ");
	printf("\n 5- Modificar una nota: ");
	printf("\n 6- Ordenar archivo alfabeticamente");
	printf("\n 7- Ver todos los registros");
	printf("\n\n");
	printf("\nOpccion: ");
	scanf("%d", &OP);
	
	switch(OP){
		// Crear archivo.
		case 1: 
		
		if((FP=fopen("alumnos", "wb")) == NULL) {
	  	   printf("\nError al intentar crear el archivo");
		   exit(1);
	}
	printf("\n ARCHIVO CREADO CON EXITO!!");
	fclose(FP);
	
	break;
	
	// Cargar datos. 
	case 2:
		
		
	if((FP= fopen("alumnos", "ab")) == NULL) {
		printf("\nError al acceder al archivo");
		exit(1);
	}
	
		  while (ingreso == 'S') {
		  	 fflush(stdin);
			 
			 printf("\nIngrese el codigo del alumno: ");
			 scanf("%d", &alum.codigo);
			 
			 fflush(stdin);
			 printf("\nIngrese el nombre del alumno: ");
			 gets(alum.nombre);
               		
			 fflush(stdin);
			 printf("Ingrese las notas: ");
			 
			 printf("\n\n");
			 for (j=0; j<4; j++) {
			 	
			 	printf("Nota %d: ", j+1);
			 	scanf("%d",&alum.notas[j]);
			 }
			 
			 
			 fwrite(&alum, sizeof(alum), 1, FP);
			 
			 fflush(stdin);
	         
			 printf("\nDesea seguir agregando productos a la Base de datos S/N: ");
	         ingreso = getchar();
		}
		
		fclose(FP);
		break;
		
		// Calcular promedio y mostrarlo
		case 3: 
		if ((FP = fopen("alumnos","rb")) == NULL) {
			printf("\nError al abrir el archivo");
		    exit(1);
		}
		
		
		fread(&alum, sizeof(alum), 1 , FP);
		while (!feof(FP)) {
			
			alum.promedio_alumno = calcular_promedio(alum.notas);
			
		    printf("\n\n");
		    printf("\nNOMBRE: %s", alum.nombre);
		    printf("\nPROMEDIO: %f", alum.promedio_alumno);
		    
			fread(&alum, sizeof(alum), 1, FP);
		}
		
		fclose(FP);
		break;
		
	// Buscar Registro
	case 4:
		
	    if ((FP = fopen("alumnos","rb")) == NULL) {
			printf("\nError al abrir el archivo");
		    exit(1);
		}
	   
	   fflush(stdin);
	   printf("\n Ingrese el codigo del alumno que desea ver: ");
	   scanf("%d", &codigo_busqueda);
	   
	   
	   
	   fread(&alum, sizeof(alum), 1 , FP);
	   
	   while (!feof(FP)) {
	   	if(alum.codigo == codigo_busqueda){
	   	   printf("\n ALUMNO ENCONTRADO CON EXITO!!!");
	   	   printf("\n CODIGO: %d", alum.codigo);
	   	   printf("\n NOMBRE: %s", alum.nombre);  
	   	   flag_busqueda = true;
		}
		
	   	fread(&alum, sizeof(alum), 1 , FP);
	   }
	   
	   if (!flag_busqueda) {
	      printf("\n El alumno no fue encontrado");	
	   }
	   
	   fclose(FP);
	   break;
	   
	   
	   //Cambiar nota
	   case 5:

	   	if((FP = fopen("alumnos", "r")) == NULL){
	   		printf("Error al abrir el archivo");
	   		exit(1);
	   	}
	   	printf("\n Ingrese el codigo del alumno, al cual desea cambiarle una nota: ");
	   	scanf("%d", &codigo_busqueda);
	   	
	    fread(&alum, sizeof(alum), 1, FP);
	    printf("\n\n %20s \t%20s %20s", "CODIGO", "NOMBRE", "NOTAS");
	    

	    while (!feof(FP)) {
	    	if(codigo_busqueda == alum.codigo){
	         printf("\n\n\t %10d \t\t\t %-20s \t\t", alum.codigo, alum.nombre); 
		
			for (x=0; x<4; x++) {
				printf("\n\n\t\t\t\t\t\t\t%d - %10d",x+1,alum.notas[x]);
		  }
		}
		 fread(&alum, sizeof(alum), 1, FP);
	  }
	  fclose(FP);
	  
	  cambiar_nota(codigo_busqueda);
	   break;
	   
	   case 6:
	   	if((FP = fopen("alumnos","ab+")) == NULL ){
	   		printf("\nError al abrir el archivo");
	   	    exit(1);
		}
		
           fseek(FP, 0, SEEK_END);
           N = ftell(FP)/ sizeof(X);
		
		 rewind(FP);

    for (I = 0; I < N-1; I++){
        rewind(FP);
        for (J = 0; J < N-I-1; J++ ){
            fread(&X, sizeof(X),1, FP);   //J
            fread(&Y, sizeof(Y),1, FP);   //J+1

            if (strcmp(X.nombre, Y.nombre) > 0) {
                fseek(FP, (-2)*sizeof(X), SEEK_CUR); //VUELVO A J
                fwrite(&Y, sizeof(Y), 1, FP); //J
                fwrite(&X, sizeof(X), 1, FP); //J+1
                
                fseek(FP, sizeof(X)*(-1), SEEK_CUR);
            }else{
            	fseek(FP, sizeof(X)*(-1), SEEK_CUR);
			}
        }
    }

		
	   fclose(FP);
	   break;
	   
	   case 7:
	   	if ((FP = fopen("alumnos", "rb")) == NULL) {
	   		printf("Error al tratar de abrir un archivo");
	   		exit(1);
	   	}
	   	
	   	printf("ALUMNOS: ");
	   	fread(&alum, sizeof(alum), 1, FP);
	   	  printf("\n\n %20s \t%20s \t%20s", "CODIGO", "NOMBRE", "NOTAS");
		  
		  while (!feof(FP)) {
	   	    printf("\n\n\t %10d \t\t\t %-20s", alum.codigo, alum.nombre);
			 for (x=0; x<4; x++) {
				printf("\n\n\t\t\t\t\t\t\t%d - %10d",x+1,alum.notas[x]);
		  }   	
	   	    fread(&alum, sizeof(alum), 1, FP);
	   	}

	   	fclose(FP);
	   	break;
	   	
	   default:
        printf("\nOpccion incorrecta");
    	break;
	  }
	}

	
	
