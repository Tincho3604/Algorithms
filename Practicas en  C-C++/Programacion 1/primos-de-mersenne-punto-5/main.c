

#include <stdio.h>
#include <math.h>
//Prototipo de la funciones
int POT(int);
int PRIMOS(int);
//Formula --> Mp = 2p-1 

int main()
{
  int P,primo,Mp,potencia;   
    printf("Ingrese el numero P = ");
    scanf("%d", &P);
    
    primo = PRIMOS(P);
   
 
    
    
    potencia = POT(P);
    printf("2 elevado a la potencia %d es igual = %d\n",P,potencia);
    
    Mp = potencia - 1;
    printf("El resultado es de Mp: %d\n", Mp);
    
    if(primo == 1){
    printf("El numero %d es primo", Mp); 
    }else{
    printf("El numero %d NO es primo", Mp);     
    }
    

  
     
    

}//Fin del main
 


 //Funcion que me retorna 2n
 int POT(int P){
 int mp = pow(2,P);
 
 return mp;
 }
 
 

 //Funcion primos
 
  int PRIMOS(int Mp){
      int i,cont;
    
  for(int i=1;i<=Mp;i++)
{
    if(Mp % i == 0) 
    cont++;
}

if(cont==2){
   return 1;
}
else{
    return 0;
}

  
      
      
  }//Fin de la funcion Primo



 
 
