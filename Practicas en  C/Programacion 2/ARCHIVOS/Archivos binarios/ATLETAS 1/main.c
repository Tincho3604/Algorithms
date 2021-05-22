/*Se cuenta con un archivo ATLETAS, conteniendo información de un Juego Olímpico en registros con esta forma:

struct atleta {
		char NOMBRE[50];
		char DISCIPLINA[30];
		int ORO;
		int PLATA;
		int BRONCE;
};

Este archivo indica las medallas obtenidas por los atletas en cada disciplina.
ORO, PLATA y BRONCE tienen un 1 si el atleta la obtuvo, ó 0 en caso contrario.
Un atleta, en una disciplina, puede ganar una de estas medallas o bien ninguna.

Por otro lado, se cuenta con un archivo DISCIPLINAS, con registros de esta forma:

struct disciplina {
		char NOMBRE[30];
		char ORO[50];
};

El archivo DISCIPLINAS solamente tiene los nombres de ellas, el campo ORO está vacio.


Se pide, en un solo programa:

1) Imprimir en pantalla los ATLETAS, para verificar que la lectura del archivo es correcta y visualizar los datos.

2) Actualizar el archivo DISCIPLINAS para que contenga en el campo ORO el nombre del atleta que lo obtuvo.

3) Mostrar en pantalla el archivo DISCIPLINAS para corroborar los resultados.

4) Mostrar en pantalla los nombres de los atletas sin repetir.
No modificar el archivo ATLETAS original.
En el ejemplo proporcionado Pepe Gomez y Maria Perez compitieron en varias disciplinas (no deben verse repetidos).


Los archivos proporcionados son ejemplos con resultados conocidos. La prueba se hará con otros datos desconocidos.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct atleta {
		char NOMBRE[50];
		char DISCIPLINA[30];
		int ORO;
		int PLATA;
		int BRONCE;
};

struct disciplina {
		char NOMBRE[30];
		char ORO[50];
};


void MOSTRAR_ATLETAS();
void ACTUALIZAR_DISCIPLINAS();
void NO_REPETIR_ATLETAS();


int main(){

    FILE * FPATLE;
    int opccion;
    


printf("\n\n");

do{
	printf("\n\n");
    printf("\n1 -- MOSTRAR ATLETAS. \n");
    printf("\n2 -- ACTUALIZAR DISCIPLINAS. \n");
    printf("\n3 -- MOSTRAR ATLETAS NO REPETIDOS. \n");
    printf("\nIngrese una opccion: ");
    scanf("%d", &opccion);
    
    
    switch(opccion){
    	case 1: {
    		MOSTRAR_ATLETAS();
			break;
			
		case 2:
			ACTUALIZAR_DISCIPLINAS();
			break;
		
		case 3:
			NO_REPETIR_ATLETAS();
			break;
		
		default: "Error";
		    break;
	  }
    }
  }while(opccion != 4);
}



// 1) Imprimir en pantalla los ATLETAS, para verificar que la lectura del archivo es correcta y visualizar los datos.
void MOSTRAR_ATLETAS(){
    
	struct atleta ATL;
	FILE * FPATLE;
	
	if ((FPATLE = fopen("ATLETAS", "rb")) == NULL){
        printf("\n\n ERROR EN LA APERTURA DEL ARCHIVO ATLETAS");
        exit(1);
    }
	
	 fread(&ATL, sizeof(ATL), 1, FPATLE);
	 printf("\n\n %-20s \t\t%10s %10s %10s %10s","NOMBRE", "DISCIPLINA", "ORO", "PLATA", "BRONCE");
     while(!feof(FPATLE)){
    	  printf("\n\n%10s \t\t\t%10s %10d \t%10d %10d",
		        ATL.NOMBRE, ATL.DISCIPLINA, ATL.ORO, ATL.PLATA, ATL.BRONCE
		  );
		  fread(&ATL, sizeof(ATL), 1, FPATLE);
    }
     fclose(FPATLE);
}





// 2) Actualizar el archivo DISCIPLINAS para que contenga en el campo ORO el nombre del atleta que lo obtuvo.
// 3) Mostrar en pantalla el archivo DISCIPLINAS para corroborar los resultados.
void ACTUALIZAR_DISCIPLINAS(){
	struct atleta Y, X;
	struct disciplina DIS;
	FILE * FDISIPLINA, * FPATLE ;
	
	if ((FDISIPLINA = fopen("DISCIPLINAS", "r+b")) == NULL){
        printf("\n\n ERROR EN LA APERTURA DEL ARCHIVO ATLETAS");
        exit(1);
    }
    
    if ((FPATLE = fopen("ATLETAS", "rb")) == NULL){
        printf("\n\n ERROR EN LA APERTURA DEL ARCHIVO ATLETAS");
        exit(1);
    }
    
    rewind(FPATLE);
    fread(&X, sizeof(X), 1, FPATLE);
	  while(!feof(FPATLE)){
	  	if(X.ORO == 1){
	  	  strcpy(DIS.ORO, X.NOMBRE);
	  	  strcpy(DIS.NOMBRE, X.DISCIPLINA);
	  	  fwrite(&DIS, sizeof(DIS), 1, FDISIPLINA);   
		}
	    
	   fread(&X, sizeof(X), 1 , FPATLE);
	}	
	
	fclose(FPATLE);
	
	
	rewind(FDISIPLINA);
	 fread(&DIS, sizeof(DIS), 1, FDISIPLINA);
	 printf("\n\n %10s %10s ","NOMBRE", "ORO");
     while(!feof(FDISIPLINA)){
    	  printf("\n\n%10s \t%10s ",
		        DIS.NOMBRE, DIS.ORO
		  );
		  fread(&DIS, sizeof(DIS), 1, FDISIPLINA);
    }
    fclose(FDISIPLINA);
	
}


/*
4) Mostrar en pantalla los nombres de los atletas sin repetir.
No modificar el archivo ATLETAS original.
En el ejemplo proporcionado Pepe Gomez y Maria Perez compitieron en varias disciplinas (no deben verse repetidos).
*/

void NO_REPETIR_ATLETAS(){
	struct atleta ATL, Y, X;
	FILE * FATL, * TEMP;
	char AUX_NOMBRE[50];
	char AUX_TEMP_NOMBRE[50];
	int I, J, N = 0;
	
	
	
	if((FATL = fopen("ATLETAS", "rb")) == NULL){
        printf("\n\n ERROR EN LA APERTURA DEL ARCHIVO ATLETAS");
        exit(1);
    }


   if((TEMP = tmpfile()) == NULL){
		printf("Error al acceder al archivo temporal");
		exit(1);
	}
	
	
  rewind(FATL);
   
	 fread(&ATL, sizeof(ATL), 1, FATL);
	   while(!feof(FATL)){
	      fwrite(&ATL, sizeof(ATL), 1, TEMP);
	      fread(&ATL, sizeof(ATL), 1, FATL);
	  }
    fclose(FATL);
	

    fseek(TEMP, 0, SEEK_END);
    N = ftell(TEMP)/sizeof(ATL);

    rewind(TEMP);

    for (I = 0; I < N-1; I++){
        rewind(TEMP);
        for (J = 0; J < N-I-1; J++ ){
            fread(&X, sizeof(X),1, TEMP);  
            fread(&Y, sizeof(Y),1, TEMP);   
            
            if (strcmp(X.NOMBRE, Y.NOMBRE) < 0){
                fseek(TEMP, (-2)*sizeof(X), SEEK_CUR); 
                fwrite(&Y, sizeof(Y), 1, TEMP); 
                fwrite(&X, sizeof(X), 1, TEMP); 
            }
            fseek(TEMP, sizeof(X)*(-1), SEEK_CUR);
        }
    }
    
    
	    fread(&X, sizeof(X), 1, TEMP); 
	 printf("\n\n %-20s \t\t%10s %10s %10s %10s","NOMBRES", "DISCIPLINA", "ORO", "PLATA", "BRONCE");
     while(!feof(TEMP)){
     	  if(strcmp(X.NOMBRE, AUX_NOMBRE) != 0){
    	  printf("\n\n%10s \t\t\t%10s %10d \t%10d %10d",
		        X.NOMBRE, X.DISCIPLINA, X.ORO, X.PLATA, X.BRONCE
		  );
	}
	    strcpy(AUX_NOMBRE, X.NOMBRE);
        fread(&X, sizeof(X), 1, TEMP); 	
    }
  fclose(TEMP);
}



