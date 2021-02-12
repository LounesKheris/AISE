// Ce programme marche avec 2 taches seulement
//on qu'un seul send et un seul receive

#include<stdio.h>
#include<mpi.h>




int main(it argc, char ** argv){
  double somme_partielle = 0., s0;
  int i, rang;
  MPI_Status status;
  MPI_Init(&argc, &argv); //initialisation de la bib MPI
  MPI_Comm_rank(MPI_COMM_WORLD, &rang); // recupérer le rang du processus MPI

  for(i = 0; i < N/2; i++)
    somme_partielle += tab[i];

  tag = 1000;  // un nombre pour identifier le message

  if(rang == 0){
    MPI_Send(&somme_partielle, 1, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);
    //si je suis le rang 0
    // j'envois somme_partielle, 1élement, type double, au rang 1, avec le tag 1000, sur MPI_COMM_WORLD
   } else {
    MPI_Recv(&s0, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
    //sinon
    // je vais poster via un buffer s0 qui va recevoir 1 element de type double qui vient du processus 0 avec le tag 1000 sur le MOI_COMM_WORLD Eet remplir le status pasé en paramétre
    printf("SOmme_totale = %d\n", s0 + somme_partielle);
  }

  MPI_Finalize(); // aucune fonction MPI apres cet appel

  return 0; 
}
