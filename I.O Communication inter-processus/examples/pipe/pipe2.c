#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char ** argv){
  int pp[2];
  pipe(pp);
/*
  R    W
  0    1
*/
  pid_t child1 = fork();

  if(child1 == 0){
    //REMPLACE STDOUT AVEC L'ECRIRE EN FIN DE PIPE
    dup2(pp[1], STDOUT_FILENO);

    //CLOSE READ END OF THE PIPE
    close(pp[0]);
    close(pp[1]);

    char * argv1[] = {"echo", "Salut\n tout le monde", NULL};
    execvp(argv1[0], argv1);
  }else{

    pid_t child2 = fork();

    if(child2 == 0){
      //replace stdin with the read en of the pipe
      dup2(pp[0], STDIN_FILENO);
      //close write end of the pipe
      close(pp[1]);
      close(pp[0]);

      //run commands
      char * argv2[] = {"tac", "-s", " ", NULL};
      execvp(argv2[0], argv2);
    }else{
    close(pp[0]);
    close(pp[1]);
    wait(NULL);
    wait(NULL);
  }
  }

  return 0;
}
