
#include <stdio.h>

//Prototipo de la funcion
int suma_divisores(int);


int main()
{
int numero,resultado;

printf("Ingrese un numero natural: ");
scanf("%d", &numero);
   
   resultado = suma_divisores(numero);
   
   printf("La suma de los divisores es = %d", resultado);
   

}//Fin del main


int suma_divisores(int numero){
     int i, acum=0;
     
     for(i=1; i<numero; i++ ){
         
         if(numero % i == 0){
             acum += i;
         }
}
    
return acum;    
    
}//Fin de funcion suma_divisores
