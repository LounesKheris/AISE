#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char ** argv){

  int fd;
  fd = open("toto.txt", O_RDWR/*READ/WRITE*/ | O_CREAT /*CRÉER LE FICHIER*/ | O_EXCL | S_IRUSR/*AUTORISE L'USER À LIRE*/ |S_IWUSR/*autorise l'user a ecrire*/);
    
  if(fd < 0){
    printf("%d == %d", errno, EACCES);
    perror("open");
  }

  close(fd);
  return 0;
}
