#include<stdio.h>
#include<mpi.h>
#include<unistd.h>


int main(int argc, char ** argv){
  int rk, i, j, s0, s1;
 
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rk);

  int tag1 = 1000;
  int tag2 = 1001;
  
  int val = 10;
  int tab[val];

  if(rk == 0){
    MPI_Send(&val, 1, MPI_INT, 1, tag1, MPI_COMM_WORLD);
    MPI_Recv(tab, 10, MPI_INT, 1, tag2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    
    for(i = 0; i < val; i++)
      printf("%d\n", tab[i]);
}
  else{
    MPI_Recv(&s0, 1, MPI_INT, 0, tag1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    for(j = 0; j < s0; j++)
      tab[j] = j;

    MPI_Send(tab, 10, MPI_INT, 0, tag2, MPI_COMM_WORLD);
  }

  MPI_Finalize();

  return 0;
}
