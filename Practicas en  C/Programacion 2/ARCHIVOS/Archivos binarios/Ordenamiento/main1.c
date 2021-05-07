#include <stdio.h>
#include <stdlib.h>


struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int EDAD ;
};

int main(){

    struct ALUMNO X, Y;
    FILE * FP;
    int N, I, J;

    if ( (FP = fopen("BD", "r+b")) == NULL){
        printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
		exit(1);
    }

    fseek(FP, 0, SEEK_END);
    N = ftell(FP)/ sizeof(X);

    rewind(FP);

    for (I = 0; I < N-1; I++){
        rewind(FP);
        for (J = 0; J < N-I-1; J++ ){
            fread(&X, sizeof(X),1, FP);   //J
            fread(&Y, sizeof(Y),1, FP);   //J+1


            if (X.EDAD > Y.EDAD){
                fseek(FP, (-2)*sizeof(X), SEEK_CUR); //VUELVO A J
                fwrite(&Y, sizeof(Y), 1, FP); //J
                fwrite(&X, sizeof(X), 1, FP); //J+1
            }
            fseek(FP, sizeof(X)*(-1), SEEK_CUR);

        }
    }


}