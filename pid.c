#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
//processus : est un programme en cours d'execution dans la mémoire centrale
//caractérisé par un identifiant PID
//chaque programme qu'on ecrit et qu'on execute constitut un processus
int main(void){
	printf("mon PID est : %d\n", getpid());
}
