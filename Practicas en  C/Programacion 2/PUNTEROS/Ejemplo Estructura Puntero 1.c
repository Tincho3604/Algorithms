#include <stdio.h>

struct FECHA{
    int dia;
    int mes;
    int anio;
}actual;

void CORREGIR(struct FECHA *);

int main(){
    actual.dia = 5;
    actual.mes = 4;
    actual.anio = 2021;
    printf("\n");
    printf("Antes de la funcion: --> ");
    printf("\n");
    printf("Dia --> %d - Mes --> %d - Anio --> %d", actual.dia, actual.mes, actual.anio);
    printf("\n");
    
    CORREGIR(&actual);

    printf("\n");
    printf("Despues de la funcion: --> ");
    printf("\n");
    printf("Dia --> %d - Mes --> %d - Anio --> %d", actual.dia, actual.mes, actual.anio);
    printf("\n");
    return 0;
}

void CORREGIR(struct FECHA * P) {
    P -> dia = 15;
    P -> mes = 35;
    P -> anio = 41;
}

