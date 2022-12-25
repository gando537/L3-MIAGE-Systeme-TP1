/*-----------------------------------------------------------------
  File : fork0.c 
  This program illustrates the use of fork() and getpid() system calls.  
  Note that write() is used instead of printf() since the latter 
  is buffered while the former is not ! 
 -----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAXCOUNT  100
#define BUFSIZE   50

int main(void){
  int   i;
  pid_t pid;
  char  buf[BUFSIZE];

  fork();

  pid = getpid();
  for (i = 1; i <= MAXCOUNT; i++) {
    sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
    write(1, buf, strlen(buf)); /* No buffering */
  } 
}

