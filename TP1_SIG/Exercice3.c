#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

pid_t child = 0;

int cnt_pipe = 0;
int cnt_cont = 0;

void sigchild(int sig){
  switch(sig){
  case SIGCONT :
    printf("GOT sigcont\n");
    cnt_cont++;
    break;
  case SIGPIPE :
    printf("GOT sigpipe\n");
    cnt_pipe++;
    break;
  default :
    printf("Whhhhhhhhhhuuuut\n");
  }
}

void sigprint(int sig){
  printf("Child get SIGPIPE %d times SIGCONT %d times\n", cnt_pipe, cnt_cont);
  exit(0);
}
int main(int argc, char ** argv){

  child = fork();

  if(child == 0){
    signal(SIGCONT, sigchild);
    signal(SIGPIPE, sigchild);
    signal(SIGINT, sigprint);
    while(1){}

  }else{
    int i;
    for(i = 0; i < 30; ++i){
      if(rand()%2){
	kill(child, SIGCONT);
      }else{
	kill(child, SIGPIPE);

      }
      sleep(1);
    }
    kill(child, SIGINT);
    wait(NULL);
  }
}
