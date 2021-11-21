#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *pf,*qf;
  char c;

  pf=fopen("original.txt","r");
  qf=fopen("copia.txt","w");

  fscanf(pf,"%c",&c);
  
  while(c!=EOF)
 {
    fprintf(qf,"%c",c);
    fscanf(pf,"%c",&c);
 }
 
  fclose(pf);
  fclose(qf);

  system("PAUSE");
  return 0;
}


