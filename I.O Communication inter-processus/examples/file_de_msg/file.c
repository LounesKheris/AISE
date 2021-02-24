#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/time.h>


#define SIZE 1024
#define NUM_MSG 65536
double get_time(){
	struct timeval val;
	gettimeofday(&val, NULL);
	return (double)val.tv_sec + 1e-6 * val.tv_usec;
}

struct msg_t{
  long type;   // identifiant
  int data[SIZE];  // message
};

int main(int argc, char ** argv){
  
  int file = msgget(IPC_PRIVATE, IPC_CREAT | 0600); // créer une file de message 
  //ipc_private : c'est que tous les fils du processus hériteront de la file 
  //ipc_creat : si elle n'existe pas, on la crée, sinon on la réutilise
  //0600 : RD & WR pour l'utilisateur

  if(file < 0)
    perror("msgget"), 1;

  int i;
  struct msg_t m;
  m.type = 1;
  int pid = fork();

  if(pid == 0){
    int stop = 0;

    while(!stop){
      msgrcv(file, &m, SIZE*sizeof(int), 2, 0);

      if(m.data[0] == 0)
	stop = 1;
      m.type = 1;
      msgsnd(file, &m, SIZE*sizeof(int), 0);
    }
    //A====>B
    //B<====A
  }else{
    double total_time = 0.0;

    for(i = 1; i <= NUM_MSG; i++){
      m.data[0] = 1;
      m.type = 2;
      double start = get_time();
      int ret = msgsnd(file, &m, SIZE*sizeof(int), 0);

      if(ret < 0)
	perror("msgsnd"), 1;

      double end = get_time();
      total_time += end -start;

      msgrcv(file, &m, SIZE*sizeof(int), 1, 0);
    }
    //condition d'arret dans le fils
    m.data[0] = 0;
    m.type = 2;
    msgsnd(file, &m, SIZE*sizeof(int), 0);
    
    wait(NULL);
    
    fprintf(stderr, "PINGPONG takes %g usec Bandwidth is %g MB/s", 
    total_time/NUM_MSG*1e6, (double)(SIZE*NUM_MSG*sizeof(int))/(total_time*1024.0*1024.0)
    );
    msgctl(file, IPC_RMID, NULL);
  }

  
}
