#include<stdio.h>

int main(int argc, char ** argv){

  int i;
  //commence par 1, parce que le 0 c'est l'executable
  for(i = 1; i < argc; i++ ){
    printf("%s", argv[i]);
    if(i < argc - 1){
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}
