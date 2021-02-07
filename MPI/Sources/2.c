//********Nombre total de processus**********

#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){
  
  int N;
  MPI_Int(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &N);
  /*int MPI_Comm_size(MPI_Comm comm, int *size)
  **MPI_Comm_Size : retourne dans *size la taille du communicateur comm
    si comm == MPI_COMM_WORLD alors
       MPI_Comm_size retourne le nombre total de processus pouvant communiquer
*/
  printf("Nombre de processus = %d\n", N);
  MPI_Finalize();
  return 0;
}
