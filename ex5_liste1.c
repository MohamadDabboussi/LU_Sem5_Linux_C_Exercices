#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>
void main() {
fork();
if (!fork())
printf("Mon pid = %d, mon pere=%d\n", getpid(), getppid());
if (fork())
printf("pid=%d\n", fork());
}
