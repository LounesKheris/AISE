#include<stdio.h>

#define SIZE 50
int main(int argc, char ** argv){

  if(argc != 2){
    printf("Error: Usage no FIle %s", argv[0]);
  }

  FILE *fp;
  char input[SIZE];
  fp = fopen(argv[1], "a+");

  scanf("%s", input);
  fprintf(fp,"%s",input);
  fclose(fp);

  return 0;
}
/*
|          Mode          |  r   |  r+  |  w   |  w+  |  a   |  a+  |
| :--------------------: | :--: | :--: | :--: | :--: | :--: | :--: |
|          Read          |  +   |  +   |      |  +   |      |  +   |
|         Write          |      |  +   |  +   |  +   |  +   |  +   |
|         Create         |      |      |  +   |  +   |  +   |  +   |
|         Cover          |      |      |  +   |  +   |      |      |
| Point in the beginning |  +   |  +   |  +   |  +   |      |      |
|    Point in the end    |      |      |      |      |  +   |  +   |

*/
