#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>

int main(int argc, char ** argv){
  if(argc > 2){
    printf("Error: Usage, file enter%s", argv[0]);
  }

  int fp, i, ch;
  
  for(i = 1; i < argc; i++){
  
    fp = open(argv[1], O_RDONLY);
    if(fp < 0)
      perror("open");
    
    while(read(fp, &ch, 1)){
      write(STDOUT_FILENO, &ch, 1);
    }
    printf("\n");
    close(fp);
  }
  return 0;
}
