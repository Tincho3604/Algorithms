#include <stdio.h>
#include <stdlib.h>

int main(){
	 
	 FILE *O, *C;
	 char aux;
	 int num = 5;
	 
	 O  = fopen("nuevo.txt","a");
	 	 
	 if(O == NULL){
	 	printf("El archivo es inaccesible ");
	 	exit(1);
	 }
	 

	   while(!feof(O)){
	   fscanf(O,"%c\n\t",&aux);
	   printf("%c",aux);	
	 }
	
	fclose(O);
	
	return 0;
}
