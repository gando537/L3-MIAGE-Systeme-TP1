/*Fichier wait.c :   création/terminaison propre d'un processus :
a) On crée un fils.
b) Le père attend la fin de celui-ci en testant la condition de sa fin.
        On peut simuler une mauvaise fin en effectuant un 'kill' du
        processus fils.  */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	int cmpt;
	int exit_cond;
	pid_t pid;;

	cmpt = 1;
	while (cmpt <= 4){

		pid = fork();
		switch (pid) {
			case -1 : perror("Erreur de création du processus");
				exit(1);
			case 0 : /* Ce code s'exécute chez le fils */
				printf("- Création du fils %d : [pid=%d] [ppid=%d]\n", cmpt, getpid(), getppid());
				sleep(5 * cmpt); /* Duree de vie du fils */
				exit(0);
			default : /* Ce code s'exécute chez le père */
				cmpt++;		
				sleep(2);
			}
	}
	
	printf("Attente de la terminaison des fils...\n");
	cmpt = 0;
	while(cmpt < 4 ){
		pid = wait(&exit_cond);
		if (WIFEXITED(exit_cond))
			printf("Le fils [pid=%d] s'est termine correctement : %d\n", pid, WEXITSTATUS (exit_cond));
		else
			printf("Le fils [pid=%d] s'est mal termine : %d\n", pid, WTERMSIG (exit_cond));
		cmpt++;
	}
	exit(0); /* exécuté par le fils et le père */
}

