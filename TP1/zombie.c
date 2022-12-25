/** Fichier zombie.c :   Faire mourir le fils avant le pere.
    Et ce dernier ne s'en preoccupe pas !*/
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main (int argc, char *argv[]){
	(void)argc;
	(void)argv;
  int pid, ppid;
  switch(pid = fork()) {
    case -1:   /* Pb... */
      perror("Erreur du fork");
      exit(1);
    case 0:    /* Ce code s'execute chez le fils */
      ppid = getppid();
      printf("Je suis le fils (%d) et le PID de mon pere est (%d)\n",
                getpid(), ppid);
      printf("Je suis le fils et je meurs : PID %d\n",
                getpid());
	  sleep(10);
      break;
  default:   /* Ce code s'execute chez le pere */
    printf("Je suis le pere (%d) \n",getpid());
	printf("Qu'est devenu mon fils %d\n", pid);
	printf("Vous avez 30 sec pour lancer un ""ps -e -f"" et constater qu'il est zombi !\n"); 
	sleep(30);
	printf("Je suis le pere, et je meurs : PID %d\n",getpid());
   }
  printf("Fin \n");
  exit(0);
}
