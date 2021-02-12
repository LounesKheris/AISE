//Ce programme marche avec plusieurs taches
//plusieurs send et receive

#include<stdio.h>
#include<mpi.h>

int main(it argc, char ** argv){
  int i;
  MPI_Init(&argc, &argv); //initialisation de la bib MPI
  MPI_Comm_rank(MPI_COMM_WORLD, &rang); // recupérer le rang du processus MPI

  som = 0.;
  //chaque processus a N/P elements du tableau distribué, et effectue sa somme partielle
  for(i = 0; i< N/P; i++)
    som += tab[i];
  int t;

  // si c'est le processus 0, il va recevoir le message de tout le monde 
  if(rang == 0){
    /*Le processus 0 recoit P-1 message dans n'importe quelle ordre*/
    for(t = 0; t < P; t++){
      MPI_Recv( &s, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORKD, &sta );
      printf("Message reçu de #%d\n", sta.MPI_SOURCE);
      som += s;
    }
  }else {
    // sinon tout les processus ou le rang est != de 0, ils envoient leurs somme au processus 0
    MPI_Send(&som, 1, MPI_DOUBLE, 0, rang, MPI_COMM_WORLD);
  }

  MPI_Finalize(); // aucune fonction MPI apres cet appel

  return 0; 
}
