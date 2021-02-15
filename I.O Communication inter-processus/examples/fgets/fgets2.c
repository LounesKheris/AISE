#include<stdio.h>
#include<stdlib.h>

#define MAX 500

int main(int argc, char ** argv){

  char buff[MAX];
  char *ret;
  int cnt;

  while(1){

    ret = fgets(buff, MAX, stdin);
    if(!ret){
      if(feof(stdin)) // ^D fin de fichier
	return 0;
      perror("fgets"),1;
  }

  fprintf(stdout, "%s %d > %s", getenv("USER"), ++cnt, ret);
}
  return 0;
}
