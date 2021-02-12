#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(){
  FILE* fd = fopen("./monfichier.txt","r+");
  if(fd == NULL){
    perror("Erreur de l'ouverture du fichier");
  }else{
    printf("FIchier ok\n");
  }
}
