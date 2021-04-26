#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
int *pe;
int i;
int tam;

printf("Ingrese la cantidad de elementos del array");
scanf("%i",&tam);

pe=malloc(tam*sizeof(int));

printf("\n\n");

printf("\n\n Ingrese elementos: ");

for(i=0; i<tam; i++){
	scanf("%i", &pe[i]);
}

return 0;
}


