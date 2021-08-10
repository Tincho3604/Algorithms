#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv){
 int x;
 float promedio = 0;
 int suma = 0;

 for (x = 0; x <argc; x++){
       suma += atoi(argv[x]);
   }
      printf("La suma es = %d",suma);
      promedio = suma / (argc-1);
      printf("\n\nCuenta %d / %d",suma,argc-1);
      printf("\n\n La cantidad de argumentos es = %d",argc-1);
      printf("\n\n");
      printf("El promedio es = %f",promedio);
      
 return 0;
}



/*
  for (i = 0; i < N; i++) {
        for(j = 0; j< N - 1; j++)
              if (*(V) < *(V + j + 1)) {
                aux = *(V + j);
                *(V + j) = *(V + j + 1);
                *(V + j + 1) = aux;
       }
       
       
       	 for(j = 0; j< argc - 1; j++)
 	 if (*(argv) < *(argv+j+1)) {
                aux = *(argv+j);
                *(argv+j) = *(argv+j+1);
                *(argv+j+1) = aux;
              
   } 
   
     
   for (x = 0; x < argc; x++) {
       printf("\n\n %s10 \t",argv[x]);
   }
*/
