#include<stdio.h>
#include<unistd.h>

int main(int argc, char ** argv){
  printf("LOunes\n");

  printf("Kheris");
  sleep(3);
  fsync(STDOUT_FILENO);
  return 0;
}
