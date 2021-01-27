/***********************
On va modifier openMP1.c pour que 
l'execution soit de maniére simultané
 **********************/

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include"rdtsc.h"

/*inclire omp.h qui contient les fonction dont "omp_get_thread_num"
qui permet de cinnaitre le numéro du thread actuel 
*/

int main(int argc, char **argv){
  if(argc != 2)
    {
      printf("Error: Usage, %s attendu", argv[1]);
    }else{
  int nb = atoi(argv[1]);
  double before = rdtsc(); 
  int n;
#pragma omp parallel for// directive de compilation
  //openMP parallélisera automatiquement la boucle qui suit cette directive donc for 
  for(n = 0; n < nb; n++){
    int id = omp_get_thread_num();
    printf("Element %d traité par le thread %d \n", n, id);
  }
  
  //mesure rdtsc : perf
  double after=rdtsc();
  printf("%lf cycles to execute\n",after-before);
 
  return EXIT_SUCCESS;
  }
}


/****Compilation*****
     gcc openMP2.C -Wall -fopenmp -o openMP2
*/
     
