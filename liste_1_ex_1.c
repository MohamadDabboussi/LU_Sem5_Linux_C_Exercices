#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>

void main() {
int child = fork();
int c = 5;
if (!child) c += 5;
else {
child = fork();
c += 10;
if (child) c += 5;
}
printf("%d \n",c);
}
