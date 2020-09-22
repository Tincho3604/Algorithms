
#include <stdio.h>
#define max 20

int potencia(int, int);
int es_primo(int);
int es_divisible(int, int);
int Wagstaff(int);

int main(){
  int i;
  int staff;
  
 
 for(i=1; i<max; i++){
      if(es_primo(i)==1){
       printf("%d\n",Wagstaff(i));
      }
}


}//main

//Funcion potencia
int potencia (int base,int exponente){
    
    int cont=1;
    int suma=1;
    while(exponente >= cont){
        
     suma *= base;   
       cont++; 
    }
    return suma;
}//potencia


//Funcion es divisible

int es_divisible(int num, int divisor){
    
    if(num % divisor == 0){
        return 1;
    }else{
        return 0;
    }
    
}//Fin de es_divisible


//Funcion es primo
int es_primo(int num){
    int cont=1;
    int i;
    for(i=2; i<num; i++){
         
         if(es_divisible(num,i)==1){
             cont++;
         }
        if(cont==1){
            return 1;
        }else{
            return 0;
        }
    }//for
}//Fin de es_primo  




//Funcion Wagstaff
int Wagstaff (int q){

     int cociente=0;
     int suma=0;
     
   suma = potencia(2,q)+1;
   cociente = suma/3;

    return cociente;
}




