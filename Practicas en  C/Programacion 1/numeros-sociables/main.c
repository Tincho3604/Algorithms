/*NUMEROS SOCIABLES

Los números sociables representan la generalización del concepto de números amigos, 
en el cual la cadena cerrada de valores es mayor que 2.

O sea, que cada número es la suma de los divisores propios del número anterior, repitiéndose los valores al cabo de cierto orden. 
14 )   Encontrar una cadena de números sociables de 4 términos.
15 )   Encontrar una cadena de números sociables de 5 términos.

*/
#include <stdio.h>
#define MAX 15000

int suma_divisores(int);
int es_divisible(int,int);

int main(){
   
   int A;
   int B;
   int C;
   int D;
   int E;
   
   int x;
   int a;
   
for(A=1; A<MAX; A++){
    for(B=1; B<MAX; B++){
        for(C=1; C<MAX; C++){
            for(D=1; D<MAX; D++){
              //  for(E=1; E<MAX; E++){ 
            
   if((suma_divisores(A)==B) && (suma_divisores(B)==C) && (suma_divisores(C)==D)){   
        printf("\nLa numeros sociables son --> %d %d %d ",A,B,C);
          }       
        }
}
      }     
    }   
  //}  


    
    
}//Main

//Funcion es_divisible
int es_divisible(int n,int d){
    
    if(n % d == 0)
       return 1;
       else 
       return 0;
}
//Funcion suma_divisores
int suma_divisores(int n){
    int divisor;
    int suma = 0;
    
     for(divisor=1; divisor<n; divisor++){
        if(es_divisible(n,divisor) == 1) 
    suma += divisor;
      }
  return suma;  
}
    

