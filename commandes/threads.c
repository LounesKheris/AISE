#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>

pid_t
gettid(void){
  return syscall(SYS_gettid);
}

int main(int argc, char ** argv){
  #pragma omp parallel
  {
    while(1){
      printf("coucou de %ld dans process %ld\n", gettid(), getpid());
      sleep(1);
    }
  }

  return 0;
}
