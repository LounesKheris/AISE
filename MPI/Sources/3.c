//*********** Rang d'un processus ************

#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){

  int N, moi; // N : recup la taille di comm, moi : recup le rang du processus courant dans le comm
  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &N);
  MPI_Comm_rank(MPI_COMM_WORLD, &moi);

  printf("Mon rang est %d sur %d\n, moi, N");
  MPI_Finalize();
  return 0;
}
