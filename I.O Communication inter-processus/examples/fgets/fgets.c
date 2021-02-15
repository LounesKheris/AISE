#include<stdio.h>
#include<string.h>
#define MAX 500

int main(int argc, char** argv){
  if(argc != 2)
    printf("Usage : %s [PATH]\n", argv[0]), 1;

  FILE *fd = fopen(argv[1], "r");
  if(!fd)
    perror("fopen"), 1;

  char buff[MAX];
  char *ret;
  int count = 0;

  while(1){
    ret = fgets(buff, MAX, fd);
    if(!ret){
      if(feof(fd)){
	break;
      }else{
	perror("fgets"),1;
      }
    }
    fprintf(stdout,"%d : %s", ++count, ret);
    /*if(strstr(buff, "fclose")){
	printf("woot");
	}*/
  }

  fclose(fd);

  return 0;
}
