/*le moment ou le fils a touché à val, donc à la case mémoire
cette case mémoire est dupliquée virtuellement.
dans le sens ou les pages ne sont pas dupliquées mais elles ont un flag "cow : copy on write", dés quequuelqu'un essaye d'ecrire dessus,l'OS sait qu'il doit dupliquer cette page, et l'attribut au processus fils avant de la modifier  
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const **argv){
  int val = 2;
  pid_t child = fork();

  if(child == 0){
    val++;
    
  }else{
    val+=2;
    wait(NULL);
  }

  fprintf(stderr, "PID %d PPID %d VAL is %d\n", getpid(), getppid(), val);
  return 0;
}
