#include <stdio.h>
# define N 5

struct ALUMNOS{
    char nom[20];
    char sex;
    int nota;
}alumno[N];

//void CARGAR(struct FECHA *);

int main(){
    struct ALUMNOS alumno[N], * P;
    struct ALUMNOS AUX;
    int cont = 0;
    int i;
    int j;
    int k;
    int o;
   
/*
   for(i=1; i<N;i++){
   	    for(j=1; j<i; j++)
   	        printf("*");
   	        printf("\n");
        
   }
   */
   
   

     for(i=N; i>0; i--){
     	for(j=1; j<=i; j++)
   	    printf("*");
   	    printf("\n");
    }

/*    
1 2 3 4 5
*
* *
* * *
* * * *
* * * * *

     
*/
  
   
	return 0;
}



