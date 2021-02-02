#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>            
int main(void){
	int pid;
	pid = fork();
	switch(pid){
		case -1 : printf("Error \n"); 
			  return 0;
		case 0 : printf("i amchild, my PID is %d and my father's PID is %d\n", getpid(),getppid()); 
			 sleep(5);
			 printf("i was asleep\n");
			 exit(0);
			 return 0;
		default : printf("I am father, my PID is %d and i ve child, his PID is %d\n", getppid(), pid); 
			  wait(0); 
			  return 0;
	
	}

}
