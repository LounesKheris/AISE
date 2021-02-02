/***********************
-Initiation à openMP
-La boucle représente le traitement 
 de defférents éléments de maniére sequentielle
************************/

#include<stdio.h>
#include<stdlib.h>
#include"../rdtsc.h"

int main(int argc, char const *argv[]){
  if(argc!=2){
    printf("Error, %s attendu", argv[1]);
  }else{
    int nb = atoi(argv[1]);
  double before = rdtsc(); 
  int n;
  for(n = 0; n < nb; n++){
    printf("Element %d traité\n",n);
  }

  double after = rdtsc();
  printf("%lf cycles to execute", after-before);

  return EXIT_SUCCESS;
}
}
