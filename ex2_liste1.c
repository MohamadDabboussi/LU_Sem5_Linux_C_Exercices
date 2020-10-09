#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>

void main() {int i=1;
 while ( fork() )
{fork(); sleep(1); printf("iter: %d",i);i++; 
if(i==4) break; } 
printf("---Process--- \n");
}
