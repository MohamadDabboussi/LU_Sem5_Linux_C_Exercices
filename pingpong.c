#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>
void h(int sig){signal(sig,h);}
void main() 
{ 
int c;
   if(c=!fork()) {
signal(17,h);
while(1){
pause();
printf("pong\n");
kill(getppid(),15);
}
}
     else {
signal(15,h);
while(1)
{
printf("ping\n");
kill(c,17);}
pause();
}
}
