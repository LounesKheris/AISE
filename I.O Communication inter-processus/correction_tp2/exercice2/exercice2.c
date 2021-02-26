#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char ** argv){

    int pp[2];
    /*
        R   W
        0   1
    */
    pipe(pp);

    printf("Parent Only\n");
    
    pid_t child = fork();
    
    printf("Hello from %d (%d child)\n", getpid(), child);
    
    if(child == 0){
        /* 0 : R*/
        dup2(pp[1], STDOUT_FILENO);
        //CLOSE READ END OF THE PIPE
        close(pp[0]);
        close(pp[1]);

        char * echo[] = {"echo", "8+4", NULL};
        execvp(echo[0], echo);

    }else{
        
       pid_t child2 = fork();

       if(child2 == 0){
            dup2(pp[0], STDIN_FILENO);
        
            close(pp[0]);
            close(pp[1]);

            char *cat[] = {"bc", NULL};
            execvp(cat[0], cat);

       }else{

            close(pp[0]);
            close(pp[1]);
            wait(NULL);
            wait(NULL);

       }
    }
    return 0;
}