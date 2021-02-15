#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char ** argv){

  pid_t child = fork();

  if(child == 0){
    int out = open("./out.dat", O_CREAT |O_WRONLY | O_APPEND, 0600);

    dup2(out, STDOUT_FILENO);
    close(out);
    char *argv[] = {"cowsay", "COUCOU POSIX", NULL};
    execvp(argv[0], argv);
  }else{
    wait(NULL);
  }

  return 0;
}
