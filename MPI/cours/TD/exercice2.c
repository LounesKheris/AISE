#include<stdio.h>
#include<mpi.h>
#include<unistd.h>

int main(int argc, char ** argv){

  int rang, s0 = 10, s1, rk;
  int tag = 1000;

  MPI_Status sta;
  
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rk);
  if(rk == 0){
      MPI_Send(&s0, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);  
  }else{
    MPI_Recv(&s1, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &sta);
    printf("Je suis P%d et j'ai reçu la valeur %d\n", rk, s0);
  }


  MPI_Finalize();

  return 0;
}
