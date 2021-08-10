#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
int *pe;
int i;
int d;
int tam;
int suma = 0;
float promedio;

printf("\n Ingrese el tamaño del array: ");
scanf("%i",&tam);

pe=malloc(tam*sizeof(int));

printf("\n Ingrese elementos: ");

for(i=0; i<tam; i++){
	scanf("%i", &pe[i]);
	suma += pe[i];
}

printf("\nValores del array: ");
for(d=0; d<tam; d++){
	printf(" %d", *(pe+d));
}

promedio = suma / tam;

printf("\nEl promedio es: %f",promedio);

free(pe);

return 0;
}

