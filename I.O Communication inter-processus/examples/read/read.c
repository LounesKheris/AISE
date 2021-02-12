#include<unistd.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<fcntl.h>

#define MAX 500

int main(int argc, char ** argv){
  if(argc != 2){
    //Error : should pass a path
    fprintf(stderr,"Usage %s PATH\n", argv[0]);
  }
  int fd = open(argv[1], O_RDONLY); // read only
  //check fd
  if(fd < 0){
    perror("open");
    return 1;
  }

  int cnt;
  char buff[500];

  while((cnt = read(fd,buff,MAX)) !=0){ // 0 : cc'est qu'on a atteint endoffile
    if(cnt < 0){
      perror("read");
      return 1;
    }
    int ret = write(STDOUT_FILENO, buff, cnt);

    if(ret < 0){
      perror("write");
      return 1;
    }
  }
  close(fd);
  return 0;
}
