#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//fork permet de créer un processus fils au prés d'un processus pére
//notre processus pére s'appelle 2.c, va créer un processus fils a travers la fonction fork
//fork retourne 2 valeurs : 
//la premier c'est 0 au niveau du processus fils
//et la 2eme, une valeurs >0 du processus pére qui constitut l'identifiant du processus fils déja creée
//en cas d'erreur, retourne -1.
int main(void){
	int pid;
	pid = fork();
	switch(pid){
		case -1 : printf("Error \n"); return 0;
		case 0 : printf("Je suis le fils, mon PID est %d et celui de mon pére est %d\n", getpid(),getppid()); return 0;
		default : printf("Je suis le pére, mon PID est %d et j'ai un fils %d\n", getppid(), pid); wait(0); 
			        return 0;
	
	}

}
