#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main() {

 FILE * FP;
	char TEXTO[10];
	char aux[10];
	char aux_pal[5];
	int contador_pal = 0;
	char palabra[10];

	// Creamos el archivo txt para que el usuario busque
	if ((FP = fopen("palabras.txt", "w")) == NULL) {
		printf("\nError al crear el archivo");
		exit(1);
	}
	
	for (int i=0; i<=1; i++) {
	
	printf("\nIntroduce una frase: ");
    gets(TEXTO);
	
	fprintf(FP, "%s", TEXTO);
	fputc('\n', FP);
}
	fflush(FP);
	fclose(FP);
	
	
	// Buscamos la palabra y establecemos la ocurrencia
		if ((FP = fopen("palabras.txt", "r")) == NULL) {
		printf("\nError al abrir el archivo");
		exit(1);
	}
	
    printf("\nIngrese una palabra a buscar: ");
	gets(palabra);
	
	
	printf("\nLECTURA DEL ARCHIVO: \n");
      while (fgets(aux, 10, FP) != NULL){
         printf("%s", aux);
	     
		  if(strcmp(aux, palabra) == 0){
          	contador_pal++;
          }
     }
	
	if (contador_pal == 0) {
		printf("\n No se encontro la palabra solicitada");
		printf("\n La palabra solicitada fue: %10s", palabra);
	} else {
		printf("\n La cantidad de ocurrencias de la palabra buscada fue de %d", contador_pal);
		printf("\n La palabra solicitada fue: %10s", palabra);
	}
    fclose(FP);
	 	
	return 0;
}
