#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <signal.h>

void h(int sig){signal(14,h);}

void main(){
char *prg;
int sec;
signal(14,h);
while(1)
{
printf("temps et programme a execute: \n");
scanf("%d %s",&sec,prg);
if(!fork()){
alarm(sec);
pause();
execlp(prg,prg,0);
exit(0);
}
wait(NULL);
}
}
