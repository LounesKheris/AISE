#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


int main(int argc, char **argv){
  if(argc !=3){
    printf("Usage: %s [num_rows][num_cols] \n",argv[0]);

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    unsigned double* matrice_A;
    unsigned double* matrice_B;
    unsigned double* matrice_res;

    matrice_A =(double*)malloc(rows*cols*sizeof(double));
    matrice_B =(double*)malloc(rows*cols*sizeof(double));
    matrice_res =(double*)malloc(rows*cols*sizeof(double)); 

    printf("remplissage de la matrice_A\n");

    for(int i=0; i < rows; i++){
      for(int j=0; j < cols; j++){
	matrice_A(i)(j) = (double) rand()*100;
	printf("matrice[%d][%d]", i,j,matrice_A[i][j]);
	  }
    }
      
  }
