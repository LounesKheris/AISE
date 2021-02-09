#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
pid_t child = 0;

/*
  sihhandler il est appelé toutes les 3secondes, il réalarme alarm(3) de 3 sec
  
*/
void sig_handler(){
  printf("send USR1 to child\n");
  kill(child, 10);
  alarm(3);
}

void sigint(int sig){
  printf("send SIGINT to child\n");
  kill(child, 2);
  exit(1);
}

int cnt = 0;
void sigchild(int sig){
  printf("child get SIGUSR1 %d times\n", ++cnt);
}

int main(int argc, char **argv){
  child = fork();

  if(child == 0){
        signal(SIGUSR1, sigchild);
	while(1){}
  }else{
    
    signal(SIGALRM, sig_handler);
    signal(SIGINT, sigint);
    alarm(3);
    wait(NULL);
  }
  return 0;
}
