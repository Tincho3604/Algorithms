#include <stdio.h>
#include <stdlib.h>

int coprimos(int,int);

int main(){
    int numero1, numero2;
    int cont=0;
    
  srand(100);

while(cont<=50){  
numero1 = rand() % 51;
numero2 = rand() % 51;
 


if(coprimos(numero1,numero2) == 1){
    printf("\t\t\n%d-%d", numero1,numero2);
}

    cont++;
}
}//main

int coprimos(int num1, int num2){ 
   int residuo = 0;
   int mcd = 0;
 
    do {
        residuo = num1 % num2;
 
        if (residuo != 0) {
            num1 = num2;
            num2 = residuo;
 
        } else {
            mcd = num2;
        }
 
    } while (residuo != 0);
 
    if(mcd == 1){
    return 1;     
    }

}//Fin Coprimos
 
 
