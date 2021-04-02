#include <stdio.h>
# define N 5

void orden(int *);

int main(){

    int A[N] = { 4, 2, 0, 10, -5 };
    int* punt = NULL;
    int n;

    punt = A;
 

    orden(punt);
    for (int i = 0; i < N; i++) {
        printf("%d \n", *(punt + i));
    }

  
}




void orden(int * V) {

    int * P;
    int  i;
    int  j;
    int aux;

    for (i = 0; i < N; i++) {
        for(j = 0; j< N - 1; j++)
            if (*(V) < *(V + j + 1)) {
                aux = *(V + j);
                *(V + j) = *(V + j + 1);
                *(V + j + 1) = aux;
       }
    }
}

