#include<stdio.h>
#include<stdlib.h>
/*
  AA =BB
  CC=DD

  
  NULL

*/

int main(int argc, char const argv[], char const *envp[]){
  char* path = getenv("PATH");
  if(path){
    printf("%s",path);
  }

  printf("-------------------------------------");
  char **cur = envp;
  do{
    printf("%s\n", *cur);
  }while(*cur++);
    
  return 0;
}
