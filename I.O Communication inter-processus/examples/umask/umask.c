#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char ** argv){
  
  //ouvrir le c=fichier avec tous les droit puisque c NON(umask)
  umask(0000);
  int fd = open("umask.txt", O_RDWR | O_CREAT | O_EXCL | 0777);
  if(fd < 0){
    perror("open");
  }

  close(fd);

  return 0;
}
