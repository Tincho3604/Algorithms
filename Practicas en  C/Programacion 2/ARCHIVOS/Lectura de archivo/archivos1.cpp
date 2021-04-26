#include <stdio.h>

int main(){
	
	char aux;
	FILE *f;
	
	f = fopen("textotest.txt","r");
	if(f == NULL){
		printf("El fichero es inaccesible");
		return -1;
	}
	while(aux != EOF){ 
	
       aux = fgetc(f);	
	   printf("%c",aux);	
	}
	printf("\n");

	return 0;
}
