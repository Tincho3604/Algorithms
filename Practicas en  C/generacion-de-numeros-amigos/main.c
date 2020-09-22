/*GENERACION DE NUMEROS AMIGOS

Hacia el año 850, el matemático islámico Tabit Ibn Qurra, descubrió que si se daba la relación:

P   = 3 * 2n-1 – 1  
Q  = 3 * 2n – 1  
R   = 9 * 22n-1 – 1  

donde n > 1  y  P , Q y R son números primos, entonces :

( 2n PQ  ,  2n R )  

conforman un par de números amigos.

13 )   Encontrar 3 valores de n que cumplan con lo anterior y mostrar los pares de números amigos que forman. 
*/


#include <stdio.h>

long es_primo(long);
int potencia(int, int);
long es_perfecto (long);
long suma_divisores (long);
int es_divisible (int,int);


int main(){
  
  long P;
  long Q;
  long R; 
  
  int cont=0;
  int x;
  int i;
  long par1;
  long par2;


for(i=2; i<10; i++){
    
  P = 3 * potencia(2,i-1) - 1;
  Q = 3 * potencia(2,i) - 1;
  R = 9 * potencia(2,2*i-1) - 1;


   if((es_primo(P)==1) && (es_primo(Q)==1) && (es_primo(R)==1)){

x= i;

par1 = potencia(2,x)*(P*Q);
par2 = potencia(2,x)*R;
}   

}//For    
 
 if((suma_divisores(par1)==par2) && (suma_divisores(par2)==par1)){

printf("\nEste par [%ld - %ld] --> SI son numeros amigos --> El [n] es %d",par1,par2,x);
cont++;
     
 }else{
    printf("Este par de numeros NO son numeros amigos");
}
 

 
 
 
}//Main

long es_primo(long nu){
    int i;
    int cont=1; 
    for(i=2; i<nu; i++){
    if(nu % i == 0)
    cont++;
    }
    if(cont==1)
    return 1;
    else
    return 0;
}//es_primo

int potencia(int base,int exponente){
    
int cont=1;
int mult=1;

    while(exponente >= cont){
    mult *= base;
    cont++;
}
return mult;    
}//fin potencia



//Funcion es_divisible
int es_divisible(int n,int d){
    
    if(n % d == 0)
       return 1;
       else 
       return 0;
}
//Funcion suma_divisores
long suma_divisores(long n){
    int divisor;
    long suma = 0;
    
     for(divisor=1; divisor<n; divisor++){
        if(es_divisible(n,divisor) == 1) 
    suma += divisor;
      }
  return suma;  
}
    



