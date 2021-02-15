#include<stdio.h>

int main(int argc, char ** argv){

  if(argc != 2)
    printf("Usage %s [PATH]\n", argv[1]), 1;

  FILE * fd = fopen(argv[1], "r");

  if(!fd){
    perror("fopen");
    return 1;
  }
  fclose(fd);

  return 0;
}
