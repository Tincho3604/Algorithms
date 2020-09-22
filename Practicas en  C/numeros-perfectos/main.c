
#include <stdio.h>


//Prototipo de  las funciones
int PERFECTO(int);
int PERFECTO_MOSTRAR_NUMEROS();


int main()
{
  int numero,num_perfecto,mostrar;
  
  /*
  
  printf("Ingrese un numero natural: ");
  scanf("%d", &numero);
  
  num_perfecto=PERFECTO(numero);
  
  if(num_perfecto == 1){
  printf("El numero %d es perfecto", numero);
}else{
  printf("El numero %d no es perfecto", numero);
}

 printf("\n\n");
 
*/

  mostrar = PERFECTO_MOSTRAR_NUMEROS();
  printf("Los primeros 4 numeros perfectos son:  \n%d\n", mostrar);
  
  
  
  
  
  
   
}// Fin de la funcion main



//Con esta funcion PERFECTO retorno 1(Si el numero es perfecto)  o  0(Si el numero no es perfecto)
int PERFECTO(int numero){
    int i,acum;
    
    for(i=1; i<numero; i++){
        if(numero % i == 0)
        acum += i;
        }
  
      if(acum == numero){
        
        return 1;
    }else{
        return 0;
    }

}//Fin de la funcion PERFECTO


//Con esta funcion PERFECTO_MOSTRAR_NUMEROS mostramos los primeros 4 numero perfectos
int PERFECTO_MOSTRAR_NUMEROS(){
   int i, j=1, acum,cont=0;


	for (i=1; i<34000000; i++){
		acum=0;
	
	
		while (i>j){
    	if (i % j == 0)
			acum += j;
			j++;
		}
		
		
		j=1;
		
		if (i==acum)
		
		return i;
        
		}
    }//fin de la funcion 


