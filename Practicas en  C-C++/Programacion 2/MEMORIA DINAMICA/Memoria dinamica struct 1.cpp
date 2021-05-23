#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct ALUMNO{
	int legajo;
	char sexo;
	char nombre[30];
	float promedio;
};

int main(){

struct ALUMNO * alumno;

alumno=(struct ALUMNO *) malloc(3 * sizeof(struct ALUMNO));

printf("\nIngrese los datos de los alumnos :");

for(int i=1; i<4; i++){
	printf("\nALUMNO N %d: ",i );
      scanf("%s", alumno[i].nombre);
}

	printf("\nLISTADO DE ALUMNO");
for(int j=1; j<4; j++){
	printf("\nALUMNOS N %d: ",j );
	printf("%s",alumno[j].nombre);

}
return 0;
}
