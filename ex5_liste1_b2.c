#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>
void main() {
int i;
for (i=0; i<2; i++) {fork();
if (fork())
{
printf("Premier: %d, Second: %d\n", fork(), getppid());
}
else break;
}
}
