#include<stdio.h>
#include<string.h>

int main(int argc, char ** argv){

  if(argc != 3 )
    printf("Usage : %s [PATH]\n", argv[0]);

  FILE * fd = fopen(argv[1], "a");
  if(!fd)
    perror("fopen"), 1;

  size_t cnt;

  cnt = fwrite(argv[2], sizeof(char), strlen(argv[2]), fd);

  if(cnt == 0)
    perror("fwrite"),1;

  fclose(fd);

  return 0;
   
}
