#include<stdio.h>


#define MAX 500
int main(int argc, char ** argv){

  if(argc != 2)
    printf("Usage : %s [PATH]", argv[0]), 1;

  FILE * fd = fopen(argv[1], "r");
  if(!fd)
    perror("fopen"), 1;

  char buf[MAX];
  size_t count;

  while(1){
    count = fread(buf, sizeof(char), MAX, fd);

    if(count == 0){
      if(feof(fd)){
	break;
      }else{
	perror("fread"), 1;
      }
	  
    }
    }

  fclose(fd);

  return 0;
}
