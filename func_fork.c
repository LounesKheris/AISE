#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int i;
void work(char *c){
  i =rand()%4;
  printf("randum value 'i' pour le %s is %d\n",c, i);
}
int main(void){
	int pid;
	pid = fork();
	switch(pid){
		case -1 : printf("Error \n"); 
			  return 0;
		case 0 : printf("i amchild, my PID is %d and my father's PID is %d\n", getpid(),getppid()); 
		  work("child");
			  return 0;
		default : printf("I am father, my PID is %d and i ve child, his PID is %d\n", getppid(), pid); 
		  work("parent"); 
			  return 0;
	
	}

}
