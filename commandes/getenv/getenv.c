#include<stdio.h>
#include<stdlib.h>
/*
  AA =BB
  CC=DD

  
  NULL

*/

int main(int argc, char const *argv[], char const *envp[]){

  char *path = getenv("PATH");
  if(path){
    printf("%s\n", path);
  }
  return 0;
}
