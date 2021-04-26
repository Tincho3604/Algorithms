#include <stdio.h>

// Copiar un archivo de Texto (Descargado) a otro Nuevo.

int main(){
	
	char aux;
	FILE *f;
	FILE *c;
	char cont;
	f = fopen("original.txt","r");
	c = fopen("copia.txt","w");
	
	if(f == NULL){
		printf("El fichero es inaccesible");
		return -1;
	}
	
	while(aux != EOF){ 

       aux = fgetc(f);	
    fputc ( aux, c );
	   	
	}
	printf("\n");
    
	
	fclose(f);
	fclose(c);
	return 0;
}
