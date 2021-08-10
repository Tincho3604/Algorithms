#include <stdio.h>
#include <string.h>

struct producto {
    char nombre[40];
    float precio;
    int ventas_mes[12];
};
#define CANT_PRODUCTOS 4

void inicializar(struct producto ventas[],int cantidad){
    int i,j;
    for(i=0;i<cantidad;i++){
        for(j=0;j<12;j++){
            ventas[i].ventas_mes[j] = 0;
        }
    }
}
void mostrar_ventas_anio(struct producto ventas[],int cantidad, char nombre[]){
    int i,j;
    for(i=0;i<cantidad;i++){
        if(strcmp(ventas[i].nombre, nombre) == 0){
            int total_vendidos = 0;
            for(j=0;j<12;j++){
                total_vendidos += ventas[i].ventas_mes[j];
            }
             printf("\n\n\t %s = %d \n", ventas[i].nombre, total_vendidos);
             break;
        }
    }
}
void mostrar_precio(struct producto ventas[], int cantidad){
    float aux[cantidad],aux2;
    int i,j;
    for(i=0;i<cantidad;i++)
        aux[i] = ventas[i].precio;
    for(i=0;i<cantidad;i++){
        for(j=0;j<cantidad-1;j++){
            if(aux[j] < aux[j+1]){
                aux2 = aux[j];
                aux[j] = aux[j+1];
                aux[j+1] = aux2;
            }
        }
    }
     for(i=0;i<cantidad;i++){
        for(j=0;j<cantidad;j++){
            if(ventas[j].precio == aux[i]){
                printf("\n\t %s ",ventas[j].nombre);
            }
        }
    }
}
void mostrar_alfabetico(struct producto ventas[],int cantidad){
    int i,j;
    char aux1[25];
    char nombres[cantidad][25];
    for(i=0;i<cantidad;i++){
        strcpy(nombres[i],ventas[i].nombre);
    }
    for(i=0;i<cantidad;i++){
        for(j=0;j<cantidad-1;j++){
            if(strcmp(nombres[j],nombres[j+1]) > 0){
                strcpy(aux1,nombres[j]);
                strcpy(nombres[j],nombres[j+1]);
                strcpy(nombres[j+1],aux1);
            }
        }
    }
    printf("\n\n");
    for(i =0 ;i<cantidad;i++)
        printf("\n\t %s ", nombres[i]);
    printf("\n\n");
}

float calcular_ventas_totales(struct producto ventas[], int cantidad){
    float cantidad_vendidos;
    float costo_total = 0;
    int i,j;
    for(i=0;i<cantidad;i++){
        cantidad_vendidos = 0;
        for(j=0;j<12;j++){
            cantidad_vendidos += ventas[i].ventas_mes[j];
        }
        costo_total += cantidad_vendidos*ventas[i].precio;
    }
    return costo_total;

}
void  mostrar_mas_vendido(struct producto ventas[], int cantidad){
    int i,j;
    int vendidos_cada_producto[cantidad];
    for(i=0;i<cantidad;i++){
        vendidos_cada_producto[i] = 0;
        for(j=0;j<12;j++){
            vendidos_cada_producto[i] += ventas[i].ventas_mes[j];
        }
    }
    int indice = 0;
    for(i=0;i<cantidad;i++){
        if(vendidos_cada_producto[i] > vendidos_cada_producto[indice]){
            indice = i;
        }
    }
    printf("\n\n\t %s = %d unidades  \n",ventas[indice].nombre, vendidos_cada_producto[indice]);

}

int main() {
    struct producto ventas[CANT_PRODUCTOS];
    float aux = 0.0;
    /* PUNTO 1: Inicializar el vector de ventas_mes con ceros, para todos los productos */
     inicializar(ventas, CANT_PRODUCTOS);
    /* ahora cargo algunos productos para poder trabajar, no modificar esto */
    strcpy(ventas[0].nombre, "Arandela");
    ventas[0].precio = 1.5;
    ventas[0].ventas_mes[0] = 300; /* cantidad de arandelas vendidas en enero */
    ventas[0].ventas_mes[5] = 100; /* cantidad de arandelas vendidas en junio */
    ventas[0].ventas_mes[11] = 50; /* cantidad de arandelas vendidas en diciembre */
    strcpy(ventas[1].nombre, "Tuerca");
    ventas[1].precio = 2.2;
    ventas[1].ventas_mes[0] = 200;
    ventas[1].ventas_mes[5] = 100;
    ventas[1].ventas_mes[11] = 50;
    strcpy(ventas[2].nombre, "Tornillo");
    ventas[2].precio = 3.5;
    ventas[2].ventas_mes[0] = 400;
    ventas[2].ventas_mes[5] = 200;
    ventas[2].ventas_mes[11] = 150;
    strcpy(ventas[3].nombre, "Tarugo");
    ventas[3].precio = 5.2;
    ventas[3].ventas_mes[0] = 500;
    ventas[3].ventas_mes[5] = 300;
    ventas[3].ventas_mes[11] = 250;
    /* PUNTO 2: Mostrar las ventas que tuvo un producto en todo el año, dado su nombre */
    /* Resultado esperado: Tornillo 750 unidades */
    mostrar_ventas_anio(ventas, CANT_PRODUCTOS, "Tornillo");
    /* PUNTO 3: Mostrar todos los productos en orden decreciente de precio (más caros primero). */
    /* Resultado esperado: Tarugo Tornillo Tuerca Arandela */
    mostrar_precio(ventas, CANT_PRODUCTOS);

    /* PUNTO 4: Mostrar todos los productos en orden alfabético. */
    /* Resultado esperado: Arandela Tarugo Tornillo Tuerca */
    mostrar_alfabetico(ventas, CANT_PRODUCTOS);

    /* PUNTO 5: Calcular y retornar el dinero total vendido en el año */
    /* Resultado esperado: $ 8855.00 */
    aux = calcular_ventas_totales(ventas, CANT_PRODUCTOS);
    printf("$ %.2f", aux);

    /* PUNTO 6: Mostrar el nombre del producto más vendido (en cantidad) en el año */
    /* Resultado esperado: Tarugo 1050 unidades */
    mostrar_mas_vendido(ventas, CANT_PRODUCTOS);

    return 0;
}