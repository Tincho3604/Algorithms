#include <stdio.h>
#include <math.h>
//Prototipos de la funcion

int mersenne(int);
int primo(int);

int main()
{
  
 int numero,PRIMOS,potencia;


printf("Introduce un numero: ");
scanf("%d",&numero);

//Almaceno las Funciones en variables
potencia = mersenne(numero);
PRIMOS = primo(potencia);


//Si la funcion primo que tiene como parameto Mp osea el resultado de la funcion de la potencia, es igual a 1 ES UN NUMERO PRIMO y procedo a mostar el P y el resultado de la formula


if(PRIMOS == 1){
    printf ("El numero %d Si es primo y su P es: %d",potencia,numero);
    }else{
       printf ("El numero %d NO es primo y su P es: %d",potencia,numero);
    }
    
    
    
}//Fin de main

//Creo la funcion mersenne para obtener el valor del numero "primo" Le envio como paramento el numero que ingreso por consola.


int mersenne (int numero){
    int Mp;
    
    Mp = pow(2,numero) - 1;

    return Mp;
    
}


//Creo la funcion para averiguar si un numero es primo y le envio como paramentro la variable potencia en la cual almacene el resultado de la funcion mersenne para averiguar si el resultado de la formula es primo


int primo(int potencia){
    int cont=0,i;
   
    for(i=1;i<=potencia;i++)
{
    if(potencia%i==0) 
    cont++;
}

if(cont==2){
    return 1;
}
else
{
    return 0;
  }
    
}




