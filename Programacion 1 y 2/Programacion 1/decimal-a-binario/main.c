
#include <stdio.h>

int potencia(int, int);

int main()
{

int num,cociente,resto,bit=0,binario;
scanf("%d", &num);

cociente = num;

while(cociente > 0){
 
 resto = cociente % 2;
 cociente /= 2;   

binario += resto * potencia(10,bit) ;

printf("%d %d %d \n",bit,resto,binario);

bit++;

 }//while
}//Main


int potencia(int base, int exponente){
    int potencia=1,cont=1;
    
    while(exponente >= cont){
    
    potencia *= base;
    cont++;
         }//while

return potencia;
    }


