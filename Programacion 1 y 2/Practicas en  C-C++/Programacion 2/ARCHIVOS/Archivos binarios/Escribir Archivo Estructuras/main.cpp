#include <stdio.h>
#include <stdlib.h>
#define N 3

struct alumno{
	int nota;
	char sexo;
	char nombre[20];
};

 int main () {
    
    struct alumno ALM;
    FILE * FP;
    
    if((FP = fopen("BD","wb")) == NULL){
    	printf("Archivo inaccesible");
    	exit(1);
	}

	printf("\n\n Ingrese los nombres de los alumnos: "); 
	fread(&ALM, sizeof(ALM), 1, FP);
    for(int i=0; i<N; i++){	

	fflush(stdin);
	
	printf("\n\n NOMBRE: ");
	gets(ALM.nombre);
	
	printf("\n\n SEXO: ");
	ALM.sexo = getchar();
	
	printf("\n\n NUMERO: ");
	scanf("%d", &ALM.nota);
	
	fread(&ALM, sizeof(ALM), 1, FP);
}

    fclose(FP);
	
	return 0;
 } 
