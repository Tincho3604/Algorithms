

#include <stdio.h>

int PRIMO (int);

int main(){
    int numero;
    int resultado;
    
resultado = PRIMO(numero);
    
printf("%d", resultado);


 
}// Fin de main

int PRIMO (int numero){
 
 int primo,num,DIV;
 int cont=0;

for(num=2; num<=100 ;num++){
    for(DIV=2;DIV<=num;DIV++)
   
    if(num%DIV==0)
    cont++;
   
    if(cont==1)
    printf("%d-", num);
    cont=0;
    
}
return num;

}
 
