/*
ALGORITMO DE EUCLIDES

Se basa en que el MCD de dos números también divide al resto obtenido de dividir el mayor entre el más pequeño.

Pudiendo expresarse como --> MCD ( A , 0 ) = A
MCD ( A , B ) = MCD ( B , A % B )

11 )   Construir la función  int MCD(int , int) tal que reciba dos números enteros y retorne su MCD, calculado por el método de Euclides. Se sugiere construirla como función recursiva.  
*/


#include <stdio.h>

int Euclides(int,int);

int main(){
    
    int A;
    int B;
    
    printf("Ingrese el numero A --> ");
    scanf("%d",&A);
    
    printf("Ingrese el numero B --> ");
    scanf("%d",&B);

printf("%d",Euclides(B,A));

}//Main

int Euclides(int num1, int num2){

int mcd=0;
int residuo=0;

       do {
        residuo = num1 % num2;
 
        if (residuo != 0) {
            num1 = num2;
            num2 = residuo;
 
        } else {
       mcd = num2;
        }
 
    }while(residuo != 0);
 
return mcd;

    
}//fin de Euclides
