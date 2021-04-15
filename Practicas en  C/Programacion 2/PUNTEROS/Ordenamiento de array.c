#include <stdio.h>
# define N 7

int main(){
	int VEC[N] = {1,23,17,4,-5,100};
    int *P = NULL;
    int * aux;
    int i;
    int j;
    int x;
    int o;
 
     for (i=0; i<N; i++){
        for (j=i+1; j<N; j++){
			if(*(VEC+j) > *(VEC+i)){
				x = *(VEC+i);
				*(VEC+i) = *(VEC+j);
				*(VEC+j) = x;
		 }
       }
	 }
  
  for (o=0; o<N; o++){
  printf("%d \t",VEC[o]);
  }
 
 return 0;
}