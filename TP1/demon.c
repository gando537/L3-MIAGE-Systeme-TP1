/** Fichier : demon.c 
    voir : http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
  pid_t pid, sid; /* Our process ID and Session ID */
        
  /* Fork off the parent process */
  pid = fork();
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }
  /* If we got a good PID, then we can exit the parent process. */
  if (pid > 0) {
    printf("Futur deamon is PID %d \n",pid);
    exit(EXIT_SUCCESS);
  }
  /* A ce stade, on ne peut etre que dans le fils !*/

  /* Change the file mode mask if needed */
  umask(0);
  /* Open any logs here if needed */
  
  /* Create a new SID for the child process */
  sid = setsid();
  if (sid < 0) {
    /* Log the failure */
    exit(EXIT_FAILURE);
  }
  /* Change the current working directory if needed */
  if ((chdir("/")) < 0) {
    /* Log the failure */
    exit(EXIT_FAILURE);
  }    
  /* Close out the standard file descriptors */
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
        
  /* Daemon-specific initialization goes here */    
  /* Then The Big Loop  :  */
  while (1) {/* infinite => kill !? */
    /* Do some task here ... */
    sleep(30); /* wait 30 seconds */
  }

  exit(EXIT_SUCCESS);
}
