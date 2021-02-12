#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<errno.h>

#define MAX 500

/*safe_write 
  Le write peut interrempu par un signal, donc on doit gérer 
  le errno qui vaut EINTR
*/

ssize_t safe_write(int fd, void *buff, size_t size){
  size_t written = 0; // ce qui a été écrit
  while((size - written) != 0){
    errno = 0;
    ssize_t ret = write(fd, buff + written, size - written);

    if(ret < 0){
      if(errno = EINTR){
	continue;
      }

      perror("write");
      return ret;
    }
    written += ret;
  }
}
int main(int argc, char ** argv){
  if(argc != 2){
    fprintf(stderr,"Usage %s PATH\n", argv[0]);
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);

  if(fd < 0){
    perror("open");
    return 1;
  }

  ssize_t cnt;
  char buff[MAX];

  while((cnt = read(fd, buff, MAX)) != 0){

    if(cnt < 0){
      perror("read");
      return 1;
    }

    int ret = safe_write(STDOUT_FILENO, buff, cnt);

    if(ret < 0){
      perror("write");
      return 1;
    }
  }
}
