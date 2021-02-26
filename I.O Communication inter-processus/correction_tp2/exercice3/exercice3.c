 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char ** argv){

    int out = open("./redirect.txt", O_CREAT | O_WRONLY, 0600);

    if(out < 0)
        perror("open"), 1;
    
    dup2(out, STDOUT_FILENO);
    close(out);

    for(int i = 0; i < 4096; i++){
        printf("%d\n", i);

    }

    return 0;
}