#include <stdio.h>
#include <stdlib.h>
#define N 2

struct ALUMNO {
	char NOM[20];
	char sexo;
	int promedio;
};



  int main (){
    
    FILE * AR;
    int sumaM = 0;
    int sumaF = 0;
    
	int contM = 1;
    int contF = 1;
    
	int promedioM = 0;
    int promedioF = 0;
    
    struct ALUMNO alm;
    
	if((AR = fopen("BD", "w")) == NULL){
		printf("\n\n Error al abrir el archivo \n\n");
		exit(1);
	};
	
	printf("Ingresa los datos de los alumnos = ");
    for(int i=0; i<N; i++){
	    fflush(stdin);
	    printf("\n\n\t NOMBRE: ");
	    gets(alm.NOM);
	    printf("\n\n\t SEXO: ");
	    alm.sexo = getchar();
	    printf("\n\n\t PROMEDIO: ");
	    scanf("%d",&(alm.promedio));
	    
	    fwrite(&alm, sizeof(alm),1,AR);
	}
	
	
	
	fclose(AR);
	
	
	// --------- CALCULO DE PROMEDIO ---------
	
	if((AR = fopen("BD", "rb")) == NULL){
		printf("\n\n Error al abrir el archivo \n\n");
		exit(1);
	};
	
	fread(&alm, sizeof(alm),1,AR);
	
	while(!feof(AR)){
		
		if(alm.sexo == 'F'){
			contF++;
			sumaF += alm.promedio;
			
		}else{
			contM++;
			sumaM += alm.promedio;
		}
		
		fread(&alm, sizeof(alm),1,AR);
	}
	
	   fclose(AR);
		
		promedioF = sumaF/ contF;
		promedioM = sumaM/ contM;
		
		printf("\nPROMEDIO F = %d", promedioF);
		printf("\nPROMEDIO M = %d", promedioM);
		
		printf("\nSUMA F = %d", sumaF);
		printf("\nSUMA M = %d", sumaM);
		
		
		printf("\nCONTF %d  CONTM %d ", contF, contM);
	
    // --------- CALCULO DE PROMEDIO ---------
	
	/*
	
	if((AR = fopen("BD", "rb")) == NULL){
		printf("\n\n Error al abrir el archivo \n\n");
		exit(1);
	};
	
	
	printf("\n\n\t %-20s %10s %10s \n\n", "NOMBRE", "SEXO", "EDAD");
	fread(&alm, sizeof(alm),1,AR);
	
	while(!feof(AR)){
		fflush(stdin);
		printf("\n\n\n %-20s %10c %10d", alm.NOM, alm.sexo, alm.promedio);
		fread(&alm, sizeof(alm),1,AR);
	}
	
	
	
	fclose(AR);
	*/
	return 0;
}
