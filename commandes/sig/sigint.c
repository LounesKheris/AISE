#include<signal.h>


int main(int argc, char **argv){
  sigset_t blk;
  sigset_t sigsv;

  sigemptyset(&blk);
  sigaddset(&blk, SIGINT);


  //bloque sigint donc ^c n'arriverait pas a le faire 
  sigprocmask(SIG_BLOCK, &blk, &sigsv);

  while(1){}
  return 0;
}
