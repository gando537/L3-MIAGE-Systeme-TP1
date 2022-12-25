#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAXCOUNT  10
#define BUFSIZE   50

void ChildProcess (char *buf)
{
  	for (int i = 1; i <= MAXCOUNT; i++) {
		if(i)
			sleep(1);
    	sprintf(buf, "\tThis line is from child, value = %d\n", i);
    	write(1, buf, strlen(buf)); /* No buffering */
  	} 
}

void ParentProcess (char *buf)
{
  	for (int i = 0; i <= 62; i++) {
		if (i >= 53)
			sleep(1);
    	sprintf(buf, "This line is from parent, value = %d\n", i);
   		write(1, buf, strlen(buf)); /* No buffering */
  	} 
}

int main(void){
	
	char  buf[BUFSIZE];

  	if (fork() == 0)
  		ChildProcess(buf);
	else
		ParentProcess(buf);
  	return (0); 
}
