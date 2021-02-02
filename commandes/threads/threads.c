#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>

pid_t
gettid(void){
  return syscall(SYS_gettid);
}

void foo(){
      int a;
      printf("coucou de %ld dans process %ld my a is %p\n", gettid(), getpid(),&a);
      sleep(1);

}
int main(int argc, char ** argv){
  #pragma omp parallel
  {
    while(1){
      foo();
    }
  }

  return 0;
}
