#include <stdio.h>
# define N 2

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
   
    for (P = alumno; P < alumno + N; P++) {
        cont++;
		fflush(stdin);
        printf("ALUMNO %d\n",cont);
        printf("Ingresa NOMBRE del alumno/a:\t");
        gets(P->nom);

        printf("Ingresa SEXO del alumno/a:\t");
        P->sex = getchar();

        printf("Ingresa NOTA del alumno/a:\t");
        scanf("%d", &(P->nota));
        printf("\n");
}
   
   P = alumno;
   for(i=0; i<N-1;i++){
   	  for(j=0; j<N-i-1; j++)
   	      if((P+j)->nota < (P+j+1)->nota){			 	  
            AUX = *(P+j);
            *(P+j) = *(P+j+1);
            *(P+j+1) = AUX;
        }
   }


  
   
    printf("\n\n\n\n\t %-15s %8s %10s\n","NOMBRE","SEXO","NOTA");
    for(P = alumno, i=0; i<N; i++){
    	printf("\n\n\t %-15s %8c %10d",
		(P+i)->nom, (*(P+i)).sex, (P+i)->nota);
	}
	return 0;
}

