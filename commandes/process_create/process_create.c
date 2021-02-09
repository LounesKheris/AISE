#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char ** argv){
  pid_t child = fork();

  if(child == 0){ // si == 0, on est dans le fils
    
    fprintf(stderr,"CHILD\n");
    sleep(5);
    fprintf(stderr,"CHILD: DONE WAITING\n");
  }else{
    fprintf(stderr,"PARENT\n");
    wait(NULL); // attend que le child se termine
    fprintf(stderr,"\PARENT: CHILD DONE\n"); 
  }
  return 0;
}
